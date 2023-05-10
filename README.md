# GAME DINO RUNNING
•	Nguyễn Hoàng Điệp – 22026534
•	K67-CN16-UET
•	Bài tập: INT2215 1 - Lập Trình Nâng Cao
#  Giới thiệu 
• Dino running được lấy ý tưởng từ Dinosaur running, đây là một trò chơi mang tính giải trí cao để giết thời gian nhưng vẫn không kém phần thú vị mỗi khi mất mạng trên Chrome. Game đã trở nên vô cùng phổ biến và gắn liền với tuổi thơ của thế hệ 10X trên toàn thế giới.
•	Điểm cộng rất lớn của Dino running là nó không chỉ được nâng cấp về tính năng, độ khó của game mà còn vô cùng mãn nhãn với phần đồ hoạ sinh động, đẹp mắt.
•	Dino running được viết bằng ngôn ngữ C++, kết hợp sử dụng thư viện SDL2
# Lý do chọn game
•	Đối với phiên bản Chrome cũ, thao tác còn chưa được cải thiện, hình ảnh không được mượt mà, cộng thêm không phải người dùng nào cũng 'dễ dàng' mất kết nối Internet để truy cập vào game.
•	Đặc biệt phù hợp với hầu như mọi lứa tuổi ( trên 3), vừa giúp tăng khả năng phản xạ và tránh nhàm chán khi người dùng không có phương tiện kết nối với Internet.
•	Đây là dự án đầu tay rất phù hợp với sinh viên bởi tính đơn giản, hữu dụng và không quá phức tạp đòi hỏi các kỹ năng quá cao cấp.
•	Với độ phổ biến của của phiên bản gốc thì dino running không khó để tiếp cận với người chơi.
•	Một phần vì đây chính là một tựa game mình yêu thích từ rất lâu.
# Luật chơi
•	Người chơi sử dụng các phím mũi tên và xuống để giúp chú khủng long nhảy lên và cúi xuống tránh các chương ngại vật để đi được quãng đường xa nhất.
•	Điểm số sẽ tỉ lệ thuận với thời gian mà người chơi chơi được khi chưa va phải vật cản ( tức là càng chơi lâu thì điểm càng cao ) , điểm chơi cao nhất sẽ được hệ thống ghi nhận lại
# Mô tả tính năng
![image](https://github.com/hoangdiep2710/hello/assets/125895429/9ea4b519-dd48-435a-b0eb-430debae0b63)
•	Click vào Play để bắt đầu game
•	Click vào Quit hoặc biểu tượng X ở góc phải màn hình để thoát game
![image](https://github.com/hoangdiep2710/hello/assets/125895429/963569cc-16e7-49b5-94da-d9b58d85a681)
•	Trong quá trình chơi thì người chơi, có việc bận thì bấm biểu tượng dừng để dừng lại 
•	Click vào biểu tượng âm thanh để bật hoặc tắt âm thanh
![image](https://github.com/hoangdiep2710/hello/assets/125895429/ae768e95-1cf3-41ee-9843-8abbfff7570f)
•	Click vào continue để tiếp tục chơi
•	Click 2 lần vào Menu để chơi lại giao diện ban đầu để bắt đầu lại game mới
![image](https://github.com/hoangdiep2710/hello/assets/125895429/1a013b8d-5382-49a8-a2b6-12a75f1f35dd)
•	Khi người chơi va chạm với vật cản mà điểm nhỏ hơn hoặc bằng 200 thì sẽ load ra giao diện như trên
![image](https://github.com/hoangdiep2710/hello/assets/125895429/ce601907-d75a-4502-bec4-9d69c7bf201f)
•	Khi người chơi va chạm với vật cản mà điểm lớn hơn 200 và nhỏ hơn hoặc bằng 450 thì sẽ load ra giao diện như trên
![image](https://github.com/hoangdiep2710/hello/assets/125895429/9c73ec9c-e007-4259-b06c-96197dcd3463)
•	Khi người chơi va chạm với vật cản mà điểm lớn hơn hoặc bằng 450 thì sẽ load ra giao diện như trên
•	Vật cản chính là 1 cây xương rồng cute:)) nhưng khi điểm lớn hơn 150 sẽ xuất hiện thêm 1 con chim vô cùng thật trân.
•	Nếu chơi đủ lâu thì người chơi sẽ được trải qua 3 lần thay đổi cảnh.
•	Càng chơi lâu thì tốc độ của vật cản sẽ càng tăng làm cho độ khó của game khó dần.
 # Hướng dẫn cài đặt  
•	Cài đặt sẵn VS code hoặc Visual studio…..
•	Tải các thư viện hỗ trợ SDL: SDL2, SDL2_mixer, SDL2_image, SDL2_ttf.
•	Tải source code về giải nén và click zô diep.exe và chơi game.
 # TỔNG KẾT
 Lợi ích:
•	Đã có thể tự tay làm ra một game đầu tay mà mình yêu thích từ rất lâu.
•	Trau dồi thêm được nhiều kỹ năng năng mềm với github, edit ảnh, ……
•	Cải thiện và trau dồi được thêm rất nhiều kĩ năng về lập trình
•	Rèn luyện được thêm về khả năng tự học
•	Biết cách sử dụng SDL2 với những thao tác cơ bản như(load ảnh, sự kiện chuột, render chữ lên màn hình bằng ttf,..).

Hạn chế:
•	Thuật toán về toạ độ cho các chướng ngại vật còn có phần chưa hợp lý
•	Chưa đa dạng về các loại vật cản
•	Các tính năng trong game còn thiếu phần đa dạng.
•	Còn nhiều thiếu sót trong việc trình bày code .

Định hướng phát triển:
•	Thêm tính năng chọn nhân vật, thêm vật cản để làm cho game trở nên hấp dẫn hơn
•	Có thể thêm những vật dụng trên đường để nhân vật trang bị thêm (giống tựa game Dino Swords) 
•	Tạo ra tính năng thêm mạng cho nhân vật….
# Resource
https://lazyfoo.net/tutorials/SDL/
https://github.com/tiendat-aops/dinosaur


