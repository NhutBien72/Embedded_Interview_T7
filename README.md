# C PROGRAMMING
  
## C CƠ BẢN
### Biến
  - uint8_t có kích thước 2^8 và có giá trị từ 0 -> 2^8-1
  - int16_t có kích thước 2^16 và có giá trị từ -(2^16)/2 -> (2^16)/2-1 
### Typedef
  - Định nghĩa lại nhưng bản chất không thay đổi nhằm rút gọn
  - VD: typedef unsigned char uint8_t sau này khi sử dung chỉ cần dùng uint8_t để thay thế cho unsigned char uint8_t.
### Struct
  - Struct là kiểu dữ liệu do người dùng tự định nghĩa
  - VD:
```sh
    #include <stdio.h>
     #include <stdint.h>
     struct ToaDo
    {
      uint8_t x;
      uint8_t y;
    };
    int main()
    {
      struct ToaDo diemM;
      diemM.x = 10;
      diemM.y = 3;
      printf("toa do diem M la %d, %d\n", diemM.x, diemM.y);
      return 0;
    }
```

## POINTER
### 1. Pointer
- Khai báo con trỏ: Kiểu dữ liệu* Tên;
- VD: int* ptr;
  ### 2. Con trỏ Void
- Khai báo: Void* ptr; 
-> là con trỏ đặc biệt có thể trỏ được mọi đối tượng, nhưng nó không xác định được địa chỉ đang trỏ tới có kiểu dữ liệu gì
- Kích thước của con trỏ phụ thuộc vào kiến trúc vi xử lý. VD vxl kiến trúc 64bit thì kích thước con trỏ là 64/8= 8byte.
=> Ép kiểu dữ liệu cho con trỏ: (int*)ptr;
   Lấy giá trị *(int*)ptr;
### 3. Con trỏ hàm (Funcion pointer)
   - Trỏ đến địa chỉ hàm
- VD: void (*ptr) (int,int); : ptr là con trỏ hàm có kiểu trả về là void và có kiểu input là (int,int)
### 4. Con trỏ NULL
- Khai báo con trỏ phải gán giá trị ban đầu
- Nếu khai báo chưa sử dụng phải gán = NULL
- NULL là con trỏ có giá trị = 0 và có địa chỉ = 0
- Và khi sử dụng xong cũng phải trả về NULL
### 5. Con trỏ cấp 2 (Pointer to Pointer)
- Con trỏ cấp 2 vẫn là một con trỏ, nên khi truy xuất giá trị của p_to_p chúng ta lấy được địa chỉ mà nó trỏ đến (địa chỉ của biến ptr)
- p_to_p tương đương với &ptr: chính là địa chỉ mà con trỏ cấp 2 trỏ tới, hay chính là địa chỉ của con trỏ ptr
- *p_to_p tương đương với ptr: chính là giá trị của con trỏ ptr, hay cũng chính là địa chỉ ô nhớ mà ptr trỏ tới, cũng chính là địa chỉ của biến value
- **p_to_p tương đương với *ptr hay chính là giá trị ô nhớ mà con trỏ ptr trỏ tới, cũng chính là giá trị của biến value.
- VD:
  ```sh
    int value = 100;
    int *ptr = &value;
    int **p_to_p = &ptr;
  ```
  
## MEMMORY LOCATION
  Trên RAM có 5 phân vùng bộ nhớ: Text, Data, BSS, Heap, Stack
### 1. Text
- Quyền truy cập chỉ Read và nó chứa lệnh để thực thi nên tránh sửa đổi instruction
- Chứa khai báo hằng số trong chương trình (.rodata)
### 2. Data (Initialized Data)
- Quyền truy cập là read-write
- Chứa biến toàn cục hoặc biến static với giá trị khởi tạo KHÁC 0
- Được giải phóng khi kết thúc chương trình => Tính từ lần đầu tiên khai báo. VD: ban đầu khởi tạo ở Data thì sẽ ở Data
### 3. BSS (Uninitialized Data)
- Quyền truy cập là read-write
- Chứa biến toàn cục hoặc biến static với giá trị khởi tạo BẰNG 0 hoặc KHÔNG KHỞI TẠO
- Được giải phóng khi kết thúc chương trình => Tính từ lần đầu tiên khai báo. VD: ban đầu khởi tạo ở BSS thì sẽ ở BSS
### 4. Heap
- Quyền truy cập là read-write
- Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc, …
- Sẽ được giải phóng khi gọi hàm free,…
### 5. Stack
- Quyền truy cập là read-write
- Được sử dụng cấp phát cho biến local, input parameter của hàm,…
- Sẽ được giải phóng khi ra khỏi block code/hàm
### 6. So sánh Heap và Stack
- Bộ nhớ Heap và bộ nhớ Stack bản chất đều cùng là vùng nhớ được tạo ra và lưu trữ trong RAM khi chương trình được thực thi
- Bộ nhớ Stack được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào... Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch
- Bộ nhớ Heap được dùng để lưu trữ vùng nhớ cho những biến con trỏ được cấp phát động bởi các hàm malloc - calloc - realloc (trong C)
- Kích thước vùng nhớ
  + Stack: kích thước của bộ nhớ Stack là cố định, tùy thuộc vào từng hệ điều hành, ví dụ hệ điều hành Windows là 1 MB, hệ điều hành Linux là 8 MB (lưu ý là con số có thể khác tùy thuộc vào kiến trúc hệ điều hành của bạn)
  + Heap: kích thước của bộ nhớ Heap là không cố định, có thể tăng giảm do đó đáp ứng được nhu cầu lưu trữ dữ liệu của chương trình
- Đặc điểm vùng nhớ
  + Stack: Vùng nhớ Stack được quản lý bởi hệ điều hành, dữ liệu được lưu trong Stack sẽ tự động hủy khi hàm thực hiện xong công việc của mình
  + Heap: Vùng nhớ Heap được quản lý bởi lập trình viên (trong C hoặc C++), dữ liệu trong Heap sẽ không bị hủy khi hàm thực hiện xong, điều đó có nghĩa bạn phải tự tay hủy vùng nhớ bằng câu lệnh free (trong C), và delete hoặc delete [] (trong C++), nếu không sẽ xảy ra hiện tượng rò rỉ bộ nhớ
NOTE: Việc tự động dọn vùng nhớ còn tùy thuộc vào trình biên dịch trung gian
- Vấn đề lỗi xảy ra đối với vùng nhớ
  + Stack: bởi vì bộ nhớ Stack cố định nên nếu chương trình bạn sử dụng quá nhiều bộ nhớ vượt quá khả năng lưu trữ của Stack chắc chắn sẽ xảy ra tình trạng tràn bộ nhớ Stack (Stack overflow), các trường hợp xảy ra như bạn khởi tạo quá nhiều biến cục bộ, hàm đệ quy vô hạn,...
VD: Tràn bộ nhớ Stack với hàm đệ quy vô hạn:
sh```
  int foo(int x)
  {
    printf("De quy vo han\n");
    return foo(x);
 ```
  + Heap: Nếu bạn liên tục cấp phát vùng nhớ mà không giải phóng thì sẽ bị lỗi tràn vùng nhớ Heap (Heap overflow), nếu bạn khởi tạo một vùng nhớ quá lớn mà vùng nhớ Heap không thể lưu trữ một lần được sẽ bị lỗi khởi tạo vùng nhớ Heap thất bại
VD: Trường hợp khởi tạo vùng nhớ Heap quá lớn:
sh```
int *A = (int *)malloc(18446744073709551615);
```
### 7. Cấp phát động
- Malloc/Calloc: trả về con trỏ void (void*) nên cần ép kiểu dữ liệu trả về
- Realloc: thay đổi kích thước ô nhớ
- VD: uint8_t *ptr = (uint8_t *)malloc(5); -> Malloc tạo 5 ô nhớ mỗi ô nhớ 1 byte
- Tổng quát:
  + Malloc: uint8_t * ptr = (uint8_t *)malloc(5 * sizeof(uint8_t));
  + Calloc: uint8_t * ptr = (uint8_t *)calloc(5, sizeof(uint8_t));
- Thay đổi kích thước ô nhớ Realloc: ptr = (uint8_t *)realloc(ptr, 7 * sizeof(uint8_t));
- Giải phóng: free(ptr);

## VARIABLE
### Static
- Được lưu ở phân vùng Data/BSS.
- Biến Static cục bộ:
  + Khi 1 biến được khai báo Static thì sẽ chỉ khởi tạo 1 lần duy nhất và tồn tại suổt thời gian chạy chương trình.
  + Giá trị không bị mất đi khi kết thúc chương trình mà chỉ bị thu hồi bởi Data/BSS.
  + Chỉ có thể gọi nội bộ trong hàm khởi tạo nó.
  + Mỗi lần gọi giá trị của nó sẽ bằng giá trị gần nhất hàm được gọi.
  + Static cục bộ thường dùng cho hàm có tham số trả về là địa chỉ.
- Biến Static toàn cục:
  + Chỉ được truy cập và sử dụng trong File chứa nó, KHÔNG CÓ CÁCH NÀO LẤY ĐƯỢC để sử dụng cho chương trình khác chung Folder.
  + Static toàn cục thường sử dụng để xây dựng thư viện để người dùng không thay đổi được tránh bị sai lệch.
### Extern
- Dùng để lấy hàm/biến có sẵn của các File khác cùng 1 Folder để sử dụng trừ biến Static.
- Có thể khai báo toàn cục hay cục bộ đều được.
-> Dùng lệnh `gcc filename1.c filename2.c -o filename3` để tạo filename3 từ filename1.c và filename2.c

-> Để chạy filename3 dùng lệnh `./filename3`
### Volatile
- Việc khai báo biến volatile là rất cần thiết để tránh những lỗi sai khó phát hiện do tính năng optimization của compiler.
### Regiter
- Dùng để lưu Data, thông tin giống như RAM nhưng bộ nhớ ít hơn RAM, tốc độ nhanh hơn RAM do chỉ giao tiếp với ALU.
ALU <- Register <- RAM
ALU -> Register -> RAM
- Biến được khai báo sẽ lưu trên RAM -> RAM gửi thông tin về Register -> Register gửi thông tin về ALU -> ALU thực hiện thuật toán -> ALU trả về Register -> Register trả về và lưu giá trị trên RAM.

## STRUC, UNION
- Về mặt ý nghĩa, struct và union cơ bản giống nhau. Tuy nhiên, về mặt lưu trữ trong bộ nhớ, chúng có sự khác biệt như sau:
- Struct: Dữ liệu của các thành viên của struct được lưu trữ ở những vùng nhớ khác nhau -> Do đó kích thước của 1 Struct tối thiểu bằng kích thước các thành viên cộng lại tại vì còn phụ thuộc vào bộ nhớ đệm (struct padding).
- Union : Dữ liệu các thành viên sẽ dùng chung 1 vùng nhớ -> Do đó kích thước của Union được tính là kích thước lớn nhất của kiểu dữ liệu trong Union, việc thay đổi nội dung của 1 thành viên sẽ dẫn đến thay đổi nội dung của các thành viên khác.

## COMPLIER
![image](https://github.com/NhutBien72/Embedded_Interview_T7/assets/139468908/09735377-7be4-4803-81ee-ac831a1a2688)
### 1. Giai đoạn tiền xử lý (Pre-processor)
- Giai đoạn này sẽ thực hiện:
  + Nhận mã nguồn.
  + Xóa bỏ tất cả chú thích, comments của chương trình.
  + Chỉ thị tiền xử lý (bắt đầu bằng #) cũng được xử lý.
- Sau khi qua tiền xử lý thì file code sẽ có dạng .i
- Dùng lệnh `gcc -E filename.c -o filename.i` hoặc `gcc -E filename.i` để xem lại code sau quá trình tiền xử lý.
VD: Chỉ thị `#include` cho phép ghép thêm mã chương trình của một tệp tiêu để vào mã nguồn cần dịch. Các hằng số được định nghĩa bằng `#define` sẽ được thay thế bằng giá trị cụ thể tại mỗi nơi sử dụng trong chương trình.
### 2. Giai đoạn dịch NNBC sang Assembly (Compiler)
- Phân tích cú pháp (syntax) của mã nguồn NNBC.
- Chuyển chúng sang dạng mã Assembly là một ngôn ngữ bậc thấp (hợp ngữ) gần với tập lệnh của bộ vi xử lý.
-  Quá trình biên dịch code .i thành ngôn ngữ Assembly .s.
- Dùng lệnh `gcc filename.i -S -o filename.s` hoặc `gcc -c -S filename.c` để xem lại code sau quá trình biên dịch.
### 3. Giai đoạn dịch Assembly sang ngôn ngữ máy (Assember)
- Dịch chương trình => Sang mã máy 0 và 1.
- Một tệp mã máy (Object) .o hoặc .obj sinh ra trong hệ thống sau đó
- Dùng lệnh gcc `-c filename.c -o filename.o` để tạo ra file .o và dùng lệnh `objdump -d -Mintel filename.o` để xem code.
### 4. Giai đoạn liên kết (Linker)
- Trong giai đoạn này mã máy của một chương trình dịch từ nhiều nguồn (file .c hoặc file thư viện .lib) được liên kết lại với nhau để tạo thành chương trình đích duy nhất.
- Mã máy của các hàm thư viện gọi trong chương trình cũng được đưa vào chương trình cuối trong giai đoạn này.
- Chính vì vậy mà các lỗi liên quan đến việc gọi hàm hay sử dụng biến tổng thể mà không tồn tại sẽ bị phát hiện. Kể cả lỗi viết chương trình chính không có hàm main() cũng được phát hiện trong liên kết.
- Kết thúc quá trình tất cả các đối tượng được liên kết lại với nhau thành một chương trình có thể thực thi được (Executable hay .exe) thống nhất.
- File sau khi gộp lại sẽ có đuôi mở rộng Executable hoặc .exe trên Window, còn trên MacOS hay Linux có thể đuôi theo chỉ định hoặc không có đuôi mở rộng.
- Để chạy file code C trên Terminal dùng lệnh `gcc -o filename.exe filename.c` để tạo ra file thực thi, sau đó dùng lệnh `./filename` để chạy file thực thi.

## MACRO, FUNCION, INLINE FUNCION
### Macro
- Marco là 1 tên bất kì (do lập trình viên đặt tên) trỏ tới 1 khối lệnh thực hiện một chức năng nào đó.
- Trong quá trình tiền xử lí (pre-processor), các Macro được sử dụng trong chương trình được thay thế bởi các khối câu lệnh tương ứng.
- Định nghĩa macro bằng lệnh #define.
- Được xử lí bởi Preprocessor.
- VD: `#define SUM(a,b) a+b-> Preprocessor` khi gặp bất kỳ lời gọi `SUM(a, b)` nào thì thay ngay bằng `a+b`.
=> Macro định nghĩa cái gì thì sẽ thay thế cái đó trong quá trình tiền xử lý.
### Funcion
- Function là một đoạn chương trình có tên, đầu vào và đầu ra. Hàm có chức năng giải quyết một số vấn đề chuyên biệt cho chương trình chính. Hàm được gọi nhiều lần với các tham số khác nhau.
- Program counter: bộ đếm lấy giá trị và đọc giá trị đó (chỉ đếm và đọc giá trị). NOTE: bước nhảy phụ phuộc vào kiến trúc vi xử lí.
- Stack pointer: bộ nhớ để lưu địa chỉ.
- Đầu tiên chương trình sẽ chạy các lệnh một cách tuần tự từ địa chỉ (Program counter sẽ đếm từ địa chỉ) -> Khi thấy hàm được gọi -> Compiler sẽ phải lưu địa chỉ sau hiện tại (địa chỉ trước hàm được gọi) vào Stack (Stack Pointer) -> chuyển Program counter tới hàm được gọi, thực hiện hàm đó xong và lấy kết quả trả về -> sau đó quay lại vị trí đã lưu trong Stack poiter trước khi gọi hàm và tiếp tục thực hiện chương trình
- Điều này khiến chương trình tốn thời gian hơn là chỉ cần thay thế đoạn code đã được Compile (tức là Inline Function)
### Inline Funcion
- Inline Function được khai báo với từ khóa Inline.
- Khi Compiler thấy bất kỳ chỗ nào xuất hiện Inline Function, nó sẽ thay thế chỗ đó bởi định nghĩa của hàm đã được compile tương ứng –> Phần được thay thế không phải code mà là đoạn mã đã được compile.
- Được xử lí bởi Compiler.

### SO SÁNH MACRO - FUNCTION - INLINE FUNCTION
- Macro đơn giản là chỉ thay thế đoạn code macro vào chỗ được gọi trước khi được biên dịch.
- Inline Function thay thế đoạn mã code đã được biên dịch vào chỗ được gọi
- Function bình thường phải tạo một Function call, lưu địa chỉ trước khi gọi hàm vào stack sau đó mới thực hiện hàm và sau cùng là quay trở về địa chỉ trên stack trước khi gọi hàm và thực hiện tiếp chương trình.
- Macro khiến kích thước bộ nhớ chương trình lớn nhưng thời gian chạy nhanh -> tốc độ nhanh, kích thước lớn (code dài hơn -> file dài hơn).
- Inline Function khiến kích thước bộ nhớ chương trình lớn, tuy nhiên nó làm giảm thời gian chạy chương trình -> tốc độ nhanh, kích thước lớn.
- Function bình thường sẽ phải gọi Function call nên tốn thời gian hơn Inline Function nhưng kích thước chương trình nhỏ -> tốc độ sẽ chậm, kích thước nhỏ (code ngắn hơn -> file ngắn hơn).
