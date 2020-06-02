#include <WinSock2.h>
#include <iostream>
#pragma comment (lib , "ws2_32.lib")

void showError(const char * msg)
{
    std ::cout << "에러 : " << msg << std ::endl;
    exit (-1);
}

int main()
{
    WSADATA data;
    ::WSAStartup( MAKEWORD(2, 2), &data);

    SOCKET server = socket (AF_INET , SOCK_STREAM, IPPROTO_TCP);

    if (server == INVALID_SOCKET )
        showError ("서버 생성 실패" );

    sockaddr_in addr = { 0 };

    addr.sin_family = AF_INET ;
    addr.sin_addr.s_addr = inet_addr ("127.0.0.1" );
    addr.sin_port = htons(23000);

    if (bind( server, (sockaddr *)&addr, sizeof(addr)) == SOCKET_ERROR )
        showError ("바인딩 실패" );

    if (listen( server, SOMAXCONN) == SOCKET_ERROR)
        showError ("듣기 실패" );

    std ::cout << "클라이언트를 기다립니다.." << std::endl;

    SOCKET client = accept (server, NULL, NULL);
    closesocket (client);

    closesocket (server);
    ::WSACleanup();
    return 0;+


