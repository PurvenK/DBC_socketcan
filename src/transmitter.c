#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <net/if.h>
#include <sys/ioctl.h>

int main()
{
    int s;
    struct sockaddr_can addr;
    struct ifreq ifr;
    struct can_frame frame;

    s = socket(PF_CAN, SOCK_RAW, CAN_RAW);

    strcpy(ifr.ifr_name, "vcan0");
    ioctl(s, SIOCGIFINDEX, &ifr);

    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    bind(s, (struct sockaddr *)&addr, sizeof(addr));

    int speed = 0;
    int rpm = 800;
    int temp = 20;
    int fuel = 100;
    int voltage = 125;

    while (1)
    {
        frame.can_id = 0x100;
        frame.can_dlc = 8;

        frame.data[0] = speed & 0xFF;
        frame.data[1] = speed >> 8;

        frame.data[2] = rpm & 0xFF;
        frame.data[3] = rpm >> 8;

        frame.data[4] = temp;
        frame.data[5] = fuel;
        frame.data[6] = voltage;
        frame.data[7] = 25;

        write(s, &frame, sizeof(frame));

        printf("Speed=%d RPM=%d Temp=%d Fuel=%d Voltage=%.1f\n",
               speed, rpm, temp, fuel, voltage/10.0);

        speed += 5;
        if(speed > 120)
            speed = 0;

        rpm += 100;
        if(rpm > 5000)
            rpm = 800;

        temp += 1;
        if(temp > 120)
            temp = 20;

        fuel -= 1;
        if(fuel < 0)
            fuel = 100;

        voltage++;
        if(voltage > 150)
            voltage = 110;

        sleep(1);
    }

    return 0;
}
