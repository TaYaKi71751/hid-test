/**
 * 
 * @TODO test
 * 
 */
#include "mbed.h"
#include "USBHID.h"
#include "BufferedSerial.h"

BufferedSerial usb_serial(PA_9, PA_10);
USBHID hid(&usb_serial);

int main()
{
    usb_serial.set_baud(115200);
    HID_REPORT report;
    while (1) {
        bool succeed = hid.read(&report);
        if (succeed && report.length > 0) {
            if (succeed && report.length >= 8) {
                int keycode = report.data[2];
                printf("Received keycode: %d\n", keycode);
            }
        }
    }
}
