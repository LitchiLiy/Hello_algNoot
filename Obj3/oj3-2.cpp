/*
    1. 基本数据类型中, 整数类型带符号的, 是从-128~127, 而-128的二进制是10000000, 和00000000作出鲜明对比, 总是负数比正多1
    2. 浮点数没有负号范围, 故从e-308到e308之间的数都是正数,double
    3. 反码是为了方便加法, 补码是为了取消正0负0的影响, 补码的负0被计算机视为-128, 他没有对应的源码, 其他的255个数字都有对应的原码和反码
*/