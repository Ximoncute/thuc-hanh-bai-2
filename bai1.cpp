#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Hàm chuyển đổi số để tìm tổng nhỏ nhất (6 -> 5)
long long getMinNumber(string num_str) {
    replace(num_str.begin(), num_str.end(), '6', '5');
    return stoll(num_str);
}

// Hàm chuyển đổi số để tìm tổng lớn nhất (5 -> 6)
long long getMaxNumber(string num_str) {
    replace(num_str.begin(), num_str.end(), '5', '6');
    return stoll(num_str);
}

int main() {
    long long a, b;
    cin >> a >> b;
    
    // Chuyển A và B thành chuỗi để xử lý từng chữ số
    string a_str = to_string(a);
    string b_str = to_string(b);
    
    // Tính tổng nhỏ nhất: thay tất cả '6' thành '5'
    long long min_a = getMinNumber(a_str);
    long long min_b = getMinNumber(b_str);
    long long min_sum = min_a + min_b;
    
    // Tính tổng lớn nhất: thay tất cả '5' thành '6'
    long long max_a = getMaxNumber(a_str);
    long long max_b = getMaxNumber(b_str);
    long long max_sum = max_a + max_b;
    
    // In kết quả
    cout << min_sum << " " << max_sum << endl;
    
    return 0;
} 