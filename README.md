# Badtower
# Thông tin chung
  Họ và tên - MSSV: Bùi An Huy - 23020079
  Tên trò chơi: Badtower
  [Video demo](https://www.youtube.com/watch?v=-mEDrOMW2iE&ab_channel=B%C3%B9iAnHuy)
# Mục lục
1. [Giới thiệu game](#1Giới-thiệu-game)
2. [Cách chơi](#2Cách-chơi)
3. [Tải game](#3Tải-game)
4. [Các nguồn tham khảo](#4Các-nguồn-tham-khảo)
5. [Hướng phát triển thêm](#5Hướng-phát-triển-thêm)
# 1. Giới thiệu game
  Badtower là game kiểu đánh theo lượt. Người chơi được điều khiển 3 nhân vật đối đầu với 3 kẻ địch, vượt qua 3 màn chơi liên tiếp để giành chiến thắng.
# 2. Cách chơi
  * Hệ thống đánh theo lượt của game rất đơn giản: 3 nhân vật của người chơi ra đòn trước rồi đến 3 kẻ địch và lặp lại
  * Mỗi nhân vật (cả kẻ địch và đồng minh) có 2 kĩ năng. Kĩ năng có 2 loại: tấn công (gây sát thương) và hỗ trợ (hồi phục)
  * Người chơi chọn kĩ năng và mục tiêu bằng cách dùng bàn phím:
      - 2 phím Z và X tương ứng chiêu 1 (đánh thường) và chiêu 2.
      - Sau khi chọn kĩ năng, chọn phím 1, 2 hoặc 3 để chọn mục tiêu (kẻ địch, hoặc đồng đội với kĩ năng hỗ trợ)
      - Mỗi kĩ năng sẽ có hồi chiêu, và người chơi phải chọn kĩ năng trước khi chọn mục tiêu
  * Qua mỗi màn chơi, người chơi sẽ được chọn 1 trong 3 nâng cấp (về hitpoint hoặc sức tấn công). Máu và hồi chiêu của các nhân vật sẽ không bị reset qua mỗi màn chơi
  * Trò chơi kết thúc khi người chơi vượt qua cả 3 ải, hoặc cả 3 nhân vật của người chơi hết máu.
  * Ải cuối trong game:
  *![boss](https://github.com/purupurupkl/tower/assets/161903895/f1477e08-558e-4119-9342-0345b491fb04)
  * Hình ảnh khi thắng
  * ![won](https://github.com/purupurupkl/tower/assets/161903895/75a26894-a591-4688-bb7b-92d6dd7cc676)
  *  Hình ảnh khi thua
  *  ![lose](https://github.com/purupurupkl/tower/assets/161903895/acfaa6bf-c598-44db-b10f-ddfff93061d9)
# 3. Tải game
  * Clone repo và build
  * Hoặc chạy thẳng file .exe trong folder x64
# 4. Các nguồn tham khảo
  * Hướng dẫn setup và các chức năng cơ bản của thư viện SDL2 : [Lazyfoo](https://lazyfoo.net/tutorials/SDL/index.php)
  * Hướng dẫn chung về State Machine: [Lazyfoo](https://lazyfoo.net/articles/article06/index.php)
  * Thiết kế singleton và inheritance : [The Cherno](https://www.youtube.com/@TheCherno)
  * Đồ họa trong game:
      - Hình ảnh nhân vật, âm thanh, các icon trong game: từ game [Arknights](https://www.arknights.global/) , tải trên [Aceship's Toolbox](https://aceship.github.io/AN-EN-Tags/akhrchars.html?opname=Saga)
      - 3 background của game [GBF](https://en.wikipedia.org/wiki/Granblue_Fantasy), [link hình ảnh](https://gbf-img.com/)
      - Các hình ảnh còn lại (ảnh trước và sau game, khung trạng thái nhân vật) cũng được lấy trên mạng
  # 5. Hướng phát triển thêm
     - Ngoài các phần cơ bản trong thư viện SDL, các phần code còn lại hầu như do em tự suy nghĩ và viết, không tham khảo. Tuy nhiên cũng vì giới hạn khả năng của bản thân và thời gian mà chất lượng game chưa thực sự được như em mong muốn.
      Một số hướng phát triển, cải thiện game:
    * Cải thiện hàm render cho sạch và mượt, nhẹ hơn; thêm nhiều animation cho các hành động khác nhau
    * Thay đổi cách tải dữ liệu nhân vật
    * Xây dựng class skill khác với nhiều tính năng hơn
    * Thêm các nhân vật và màn chơi mới
    * Thay đổi nâng cấp sau ải cho đa dạng và nhiều tính năng

  
