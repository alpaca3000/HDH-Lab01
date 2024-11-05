#include "kernel/types.h"
#include "kernel/sysinfo.h"
#include "user.h"

int main() {
    struct sysinfo info;

    // Gọi sysinfo để lấy thông tin hệ thống
    if (sysinfo(&info) < 0) {
        printf("sysinfotest: sysinfo failed\n");
        exit(1);
    }

    // Kiểm tra nếu các giá trị freemem và nproc hợp lệ
    if (info.freemem > 0 && info.nproc > 0) {
        printf("sysinfotest: OK\n");
    } else {
        printf("sysinfotest: FAIL\n");
    }

    exit(0);
}
