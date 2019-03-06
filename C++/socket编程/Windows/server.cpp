// windows server part
// run environment: visual studio 2015
#include <stdio.h>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib") // 加载C:\Windows\SysWOW64\ws2_32.dll

int main() {
    // 初始化DLL
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    // 创建套接字, 文件句柄
    SOCKET servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    // 绑定套接字
    sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));
    sockAddr.sin_family = PF_INET; // IPv4
    sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // IP address
    sockAddr.sin_port = htons(1234); // port
    bind(servSock, (SOCKADDR *)&sockAddr, sizeof(SOCKADDR));

    // 监听状态
    listen(servSock, 20);

    // 接收客户端请求
    SOCKADDR clntAddr;
    int nSize = sizeof(SOCKADDR);
    SOCKET clntSock = accept(servSock, (SOCKADDR *)&clntAddr, &nSize);

    // 向客户端发送数据
    char *str = "Hello, World!";
    send(clntSock, str, strlen(str) + sizeof(char), NULL);

    // 关闭套接字
    closesocket(clntSock);
    closesocket(servSock);

    // 终止DLL的使用
    WSACleanup();

    return 0;
}