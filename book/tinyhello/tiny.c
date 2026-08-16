char *str = "hello world!\n";


void print()
{
    asm(
        ".intel_syntax noprefix\n\t"
        "mov rdi, 0x01\n\t"
        "mov rsi, %0\n\t"
        "mov rdx, 0x0D\n\t"
        "mov rax, 0x01\n\t"
        "syscall\n\t"
        ".att_syntax prefix\n\t"
        :
        :"r"(str)
        :"rax","rdi","rsi","rdx"
    );
}


void exit()
{
    asm(
        ".intel_syntax noprefix\n\t"
        "mov rax, 0x3C\n\t"
        "mov rdi, 0\n\t"
        "syscall\n\t"
        ".att_syntax prefix\n\t"
    );
}




void nomain()
{
    print();
    exit();
}