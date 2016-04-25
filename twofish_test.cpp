#include <twofish.h>
#include <string.h>

void test()
{
    Twofish_key key;
    Twofish_Byte pass[] = "0123456789abcdefghijklmnopqrstuv";
    Twofish_Byte in[] = "0123456789abcdef";
    Twofish_Byte out[] = "0123456789abcdef";

    Twofish_Byte dec[] = "FFFFFFFFFFFFFFFF";

    Twofish_prepare_key(pass, 32, &key);
    Twofish_encrypt(&key, in, out);

    Twofish_decrypt(&key, out, dec);

    memset(&key , 0, sizeof(Twofish_key));
}

void test2()
{
    Twofish_key key;
    Twofish_Byte pass[] = "0123456789abcdefghijklmnopqrstuv";
    Twofish_Byte in[] = "0123456789abcdef";
    Twofish_Byte out[] = "0123456789abcdef";
    Twofish_Byte ivec[] = "0123456789abcdef";
    int ivecn = 0;
    Twofish_Byte ivec2[] = "0123456789abcdef";
    int ivecn2 = 5;

    Twofish_Byte dec[] = "FFFFFFFFFFFFFFFF";

    Twofish_prepare_key(pass, 32, &key);
    Twofish_cfb128_encrypt(&key, in, out, 5, ivec, &ivecn);

    ivecn = 16;
    Twofish_cfb128_decrypt(&key, out, dec, 5, ivec2, &ivecn2);

    memset(&key , 0, sizeof(Twofish_key));
}


int main()
{
    if (Twofish_initialise() < 0)
        return 1;

    test();
    test2();
    return 0;
}
