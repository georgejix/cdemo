// ConsoleServer.cpp : 定义控制台应用程序的入口点。  
//  
  
#include <winsock2.h>  
#include <process.h>  
//#pragma comment(lib, "ws2_32.lib")
#include <list>  
#include <iostream>
using namespace std;
  
std::list<SOCKET> client_list;  
  
void thread_client(void * );
  
int main(int argc, char * argv[])  
{  
  
    unsigned short sPort = argc>1 ? atoi(argv[1]) : 5678;
  
    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);  
      
    if (sockfd == INVALID_SOCKET)  
    {  
        cout << "fail to create socket.\n" << endl;
        return 1;  
    }  
    sockaddr_in saddr;  
    saddr.sin_addr.s_addr = ADDR_ANY;  
    saddr.sin_port = htons(sPort);  
    saddr.sin_family = AF_INET;  
    if(bind(sockfd, (const sockaddr *)(&saddr), sizeof(saddr)))  
    {  
    	cout << "fail to bind, errno: "<<GetLastError()<<".\n" << endl;
        //DWORD dw = WSAGetLastError();
        return 2;  
    }  
  
    if (listen(sockfd, 5))  
    {  
    	cout << "fail to listen.\n" << endl;
        return 3;   
    }  
  
    cout << "Server is listening at "<< sPort<< ".\n"
           "Wating for client to connect...\n" << endl;
  
  
    for (;;)  
    {  
        sockaddr_in caddr;  
        int caddr_len = sizeof(caddr);  
        int client = accept(sockfd, (sockaddr *)&caddr, &caddr_len);  
  
        unsigned char * pAddr = (unsigned char *)&caddr.sin_addr.s_addr;  
  
        printf("[%d.%d.%d.%d : %d] coming.\n", pAddr[0], pAddr[1], pAddr[2], pAddr[3], ntohs(caddr.sin_port));
        fflush(stdout);
        //_beginthread(thread_client, 0, (void *)client);
        thread_client((void *)&client);
          
        client_list.push_back(client);
  
    }  
    return 0;  
}  
  
void thread_client(void * args)
{  
    SOCKET client = *(int *)args;
    sockaddr_in caddr;  
    int caddr_len = sizeof(caddr);  
    getpeername(client, (sockaddr *)&caddr, &caddr_len);  
    unsigned char * pAddr = (unsigned char *)&caddr.sin_addr.s_addr;  
    unsigned short usPort = ntohs(caddr.sin_port);  
  
    for (;;)  
    {  
        char szMsg [0x1000] = "";  
        if (0 >= recv(client, szMsg, sizeof(szMsg)-1, 0))  
            break;  
  
        char szEcho [0x1000] = "";  
        printf("Server Say: [%d.%d.%d.%d:%d] %s"
            , pAddr[0], pAddr[1], pAddr[2], pAddr[3]  
            , usPort  
            , szMsg);  
        fflush(stdout);
  
        send(client, szMsg, strlen(szMsg), 0);
       /* for (std::list<SOCKET>::iterator it = client_list.begin();
                it != client_list.end();  
                it ++)  
        {  
            send(*it, szEcho, strlen(szEcho), 0);
        }   */
    }  
}  
