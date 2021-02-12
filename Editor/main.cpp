//
// Created by kiper220 on 31.01.2021.
//
#include <iostream>
#include <string>
#include <cstdint>

#include <libnotify/notify.h>

int main(int argc, char * argv[] )
{
    NotifyNotification* n = notify_notification_new ("Hello world",
                                                     "some message text... bla bla",
                                                     0);
    notify_notification_set_timeout(n, 10000); // 10 seconds

    if (!notify_notification_show(n, 0))
    {
        std::cerr << "show has failed" << std::endl;
        return -1;
    }
    return 0;
}