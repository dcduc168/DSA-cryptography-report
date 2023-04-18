#include <iostream>
#include <string>

using namespace std;

// Hàm mã hóa ROT13
string rot13Encrypt(string message)
{
    string result = "";

    for (int i = 0; i < message.length(); i++)
    {
        char c = message[i];
        if (isalpha(c))
            if (isupper(c))
                result += (char)(((c - 'A') + 13) % 26 + 'A');
            else
                result += (char)(((c - 'a') + 13) % 26 + 'a');
        else
            result += c;
    }

    return result;
}

string rot13Decrypt(string message)
{
    return rot13Encrypt(message);
}

int main()
{
    // Nhập thông điệp cần mã hóa
    string message;
    cout << "Nhap vao thong diep can ma hoa: ";
    getline(cin, message);

    // Mã hóa thông điệp
    string encrypted_message = rot13Encrypt(message);
    cout << "Thong diep sau khi ma hoa: " << encrypted_message << endl;

    // Giải mã thông điệp
    string decrypted_message = rot13Decrypt(encrypted_message);
    cout << "Thong diep sau khi giai ma: " << decrypted_message << endl;

    return 0;
}
