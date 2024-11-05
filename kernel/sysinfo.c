#include "types.h"
#include "riscv.h"
#include "param.h"
#include "spinlock.h"
#include "proc.h"
#include "defs.h"
#include "sysinfo.h"

// Hàm lấy thông tin hệ thống hiện tại
int systeminfo(uint64 addr) {
    struct proc *p = myproc();  // Lấy tiến trình hiện tại
    struct sysinfo info;        // Tạo một cấu trúc sysinfo để lưu thông tin hệ thống

    // Lấy thông tin bộ nhớ trống và thông tin số tiến trình
    info.freemem = get_freemem(); 
    info.nproc = get_nproc();     

    // Sao chép dữ liệu từ kernel sang không gian người dùng tại địa chỉ addr
    if(copyout(p->pagetable, addr, (char *)&info, sizeof(info)) < 0)
        return -1;

    return 0;
}
