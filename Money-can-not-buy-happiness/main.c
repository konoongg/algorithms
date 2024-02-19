#include <stdio.h>
union Thap {
    int cr;
    struct TCr {
        unsigned char cr1:1;
        unsigned char cr2:1;
        unsigned char cr3:1;
        unsigned char cr4:1;
        unsigned char cr5:1;
        unsigned char cr6:1;
        unsigned char cr7:1;
        unsigned char cr8:1;
    } crr;
};

int main() {
    unsigned long long n;
    scanf("%llu",&n);
    for (size_t i = 0; i < n; ++i){
        union Thap var;
        
        scanf("%d",&var.cr);
        //printf("%d %d %d %d %d %d %d %d %d \n",var.cr,var.crr.cr8,var.crr.cr7,var.crr.cr6,var.crr.cr5,var.crr.cr4,var.crr.cr3,var.crr.cr2,var.crr.cr1);
        if(var.crr.cr3 == 1){
            printf("1");
        }
        else if (var.crr.cr4+var.crr.cr5 == 2){
            printf("0");
        }
        else if(var.crr.cr1+var.crr.cr6+var.crr.cr7+var.crr.cr8>=1){
            printf("1");
        }
        else{
            printf("0");
        } 

    }
    return 0;
}