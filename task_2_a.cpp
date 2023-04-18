#include <iostream>
#include <string>
using namespace std;

// Hàm mã hoá chuỗi ký tự
string encode(string text, int shift)
{
    string encodedText = ""; // Khai báo, khởi tạo chuỗi sau mã hoá

    for (int i = 0; i < text.length(); i++)
        if (isalpha(text[i])) // Chỉ xét các ký tự là chữ cái
        {
            if (isupper(text[i])) // Nếu là chữ in hoa
                encodedText += char(int(text[i] + shift - 65) % 26 + 65);
            else // Ngược lại, nếu là chữ thường
                encodedText += char(int(text[i] + shift - 97) % 26 + 97);
        }
        else // Các ký tự khác sẽ biến đổi gì
            encodedText += text[i];

    return encodedText; // Trả về kết quả cuối cùng
}

int main()
{
    string text; // Khai báo plaintext cần mã hoá
    int shift;   // Khai báo shift pattern (độ dịch chuyển)

    getline(cin, text); // Đọc vào dữ liệu plaintext
    cin >> shift;       // Đọc vào dữ liệu shift pattern

    cout << encode(text, shift) << endl; // In chuỗi kết quả ra màn hình

    return 0;
}
