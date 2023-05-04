#include <iostream>
using namespace std;

string decode(string encodedText, int shift)
{
    string text = ""; // Khai báo, khởi tạo chuỗi sau giải mã

    for (int i = 0; i < encodedText.length(); i++)
        if (isalpha(encodedText[i])) // Chỉ xét các ký tự là chữ cái
        {
            if (isupper(encodedText[i])) // Nếu là chữ in hoa
                text += char(int(encodedText[i] - shift - 65 + 26) % 26 + 65);
            else // Ngược lại, nếu là chữ thường
                text += char(int(encodedText[i] - shift - 97 + 26) % 26 + 97);
        }
        else // Các ký tự khác sẽ biến đổi gì
            text += encodedText[i];

    return text; // Trả về kết quả cuối cùng
}

int main()
{
    string encodedText; // Khai báo text cần giải mã và text

    getline(cin, encodedText); // Đọc và dữ liệu encodedText

    for (int shift = 0; shift < 26; shift++)
        cout << "Shift pattern: " << shift << ", text: " << decode(encodedText, shift) << endl; // In chuỗi kết quả ra màn hình
    return 0;                                                                                   // Kết thúc chương trình
}
