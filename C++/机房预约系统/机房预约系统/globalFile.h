#pragma once
//不同的身份可能会用到不同的文件操作，我们可以将所有的文件名定义到一个全局的文件中，只需要包含这个头文件，就可以通过宏调用
//管理员文件
#define ADMIN_FILE     "admin.txt"
//学生文件
#define STUDENT_FILE   "student.txt"
//教师文件
#define TEACHER_FILE   "teacher.txt"
//机房信息文件
#define COMPUTER_FILE  "computerRoom.txt"
//订单文件
#define ORDER_FILE     "order.txt"