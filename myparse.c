#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <ctype.h>
#include <inttypes.h>

struct ParseData
{
    uint8_t sign;   // sign bit
    int16_t exp10;  // exp in base 10
    uint64_t man10; //mantissa in base 10
};

int parse(const char *sciNote, struct ParseData *pPd)
{
    int result = 1;
    // [+-]\=
    switch (*sciNote)
    {
    case '-':
        ++sciNote;
        pPd->sign =1;
        break;

    case '+':
        ++sciNote;

    default:
        pPd->sign = 0;
        break;
    }

    pPd->exp10 = 0;

    if (isdigit(*sciNote))
    {
        // \d
        pPd->man10 = *sciNote - '0';
        sciNote++;
        // \(\.\d*\)\=
        if (*sciNote == '.')
        {
            ++sciNote;
            for (;isdigit(*sciNote); ++sciNote)
            {
                pPd->man10 = (pPd->man10 * 10) + (*sciNote - '0');      // ?
                pPd->exp10--;
            }
        }
        else
        {
        }
        // \(e[+-]\=\d\+\)\=
        if (*sciNote == 'e')
        {
            // exponent specified
            int expSign;
            int exp;
            const char *oldPtr;
            
            ++sciNote;
            switch (*sciNote)
            {
            case '-':
                ++sciNote;
                expSign = -1;
                break;

            case '+':
                ++sciNote;

            default:
                expSign = 1;
                break;
            }

            for (oldPtr = sciNote, exp = 0; isdigit(*sciNote); ++sciNote)
            {
                exp = exp * 10 + *sciNote - '0';        // ?
            }

            if (oldPtr != sciNote)
            {
                pPd->exp10 += expSign * exp;
                result = 0;
            }
            else
            {
                result = 2;
            }
        }
        else
        {
            result = 0;
        }
    }
    else
    {
        result = 1;
    }

    return result;
}

int main()
{
    int result = 1;
    struct ParseData pd;

    const char *argv[10];

    *argv = "123e-1";

    result = parse("123e-1", &pd);

    printf("Results:\n");
    printf("Sign: %d \n", pd.sign);
    printf("exp10: %d \n", pd.exp10);
    printf("mantissa: %I64d\n", pd.man10);
}