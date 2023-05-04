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
    char choice;
    cout << "Encrypt(Press E) or Decrypt(Press D)\n";
    cin >> choice;
    cin.ignore();
    string message;
    if (choice == 'E')
    {
        // Nhập thông điệp cần mã hóa
        cout << "Nhap vao thong diep can ma hoa: ";
        getline(cin, message);

        // Mã hóa thông điệp
        cout << "Thong diep sau khi ma hoa: " << rot13Encrypt(message) << '\n';
    }
    else
    {
        // Nhập thông điệp cần giải mã
        cout << "Nhap vao thong diep can giai ma: ";
        getline(cin, message);

        // Giải mã thông điệp
        cout << "Thong diep sau khi giai ma: " << rot13Decrypt(message) << '\n';
    }

    return 0;
}
