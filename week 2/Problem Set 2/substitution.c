#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
string cipher(string key, string text);
bool valid_key(string key);
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        if (((strlen(argv[1]) != 26) || !(valid_key(argv[1]))))
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string text = get_string("plaintext: ");
    string cipher_text = cipher(argv[1], text);
    printf("ciphertext: %s\n", cipher_text);
    return 0;
}

// Converts text into the cipher text using the key
string cipher(string key, string text)
{
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = tolower(key[text[i] - 97]);
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = toupper(key[text[i] - 65]);
        }
    }
    return text;
}
// Validate that the key has all letter of the alphabet and no non-letter characters
bool valid_key(string key)
{
    bool invalid = false;
    bool a = false;
    bool b = false;
    bool c = false;
    bool d = false;
    bool e = false;
    bool f = false;
    bool g = false;
    bool h = false;
    bool i = false;
    bool j = false;
    bool k = false;
    bool l = false;
    bool m = false;
    bool n = false;
    bool o = false;
    bool p = false;
    bool q = false;
    bool r = false;
    bool s = false;
    bool t = false;
    bool u = false;
    bool v = false;
    bool w = false;
    bool x = false;
    bool y = false;
    bool z = false;
    for (int ii = 0, ll = strlen(key); ii < ll; ii++)
    {
        if ((key[ii] >= 'a' && key[i] <= 'z') || (key[ii] >= 'A' && key[ii] <= 'Z'))
        {
            char letter = tolower(key[ii]);
            switch (letter)
            {
                case 'a':
                    a = true;
                    break;
                case 'b':
                    b = true;
                    break;
                case 'c':
                    c = true;
                    break;
                case 'd':
                    d = true;
                    break;
                case 'e':
                    e = true;
                    break;
                case 'f':
                    f = true;
                    break;
                case 'g':
                    g = true;
                    break;
                case 'h':
                    h = true;
                    break;
                case 'i':
                    i = true;
                    break;
                case 'j':
                    j = true;
                    break;
                case 'k':
                    k = true;
                    break;
                case 'l':
                    l = true;
                    break;
                case 'm':
                    m = true;
                    break;
                case 'n':
                    n = true;
                    break;
                case 'o':
                    o = true;
                    break;
                case 'p':
                    p = true;
                    break;
                case 'q':
                    q = true;
                    break;
                case 'r':
                    r = true;
                    break;
                case 's':
                    s = true;
                    break;
                case 't':
                    t = true;
                    break;
                case 'u':
                    u = true;
                    break;
                case 'v':
                    v = true;
                    break;
                case 'w':
                    w = true;
                    break;
                case 'x':
                    x = true;
                    break;
                case 'y':
                    y = true;
                    break;
                case 'z':
                    z = true;
                    break;
            }
        }
        else
        {
            invalid = true;
            return false;
        }
    }
    if (a && b && c && d && e && f && g && h && i && j && k && l && m && n && o && p && q && r && s && t && u && v && w && x && y &&
        z)
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}