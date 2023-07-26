# C PROGRAMMING
<details><summary> Bien </summary>
  
## C CƠ BẢN
### BIẾN 
  - uint8_t có kích thước 2^8 và có giá trị từ 0 -> 2^8-1
  - int16_t có kích thước 2^16 và có giá trị từ -(2^16)/2 -> (2^16)/2-1 
### TYPEDEF
  - Định nghĩa lại nhưng bản chất không thay đổi nhằm rút gọn
  - VD: typedef unsigned char uint8_t sau này khi sử dung chỉ cần dùng uint8_t để thay thế cho unsigned char uint8_t.
### STRUCT
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
</details>



    
