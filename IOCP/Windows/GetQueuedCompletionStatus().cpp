BOOL WINAPI GetQueuedCompletionStatus(     //IOCP 핸들에서 대기중인 I/O 작업의 결과를 검색
  HANDLE       CompletionPort,             //IOCP 핸들
  LPDWORD      lpNumberOfBytesTransferred, //I/O작업의 전송된 바이트 수를 저장할 DWORD포인터
  PULONG_PTR   lpCompletionKey,            //완료된 I/O작업의 CompletionKey를 저장할 ULONG_PTR
  LPOVERLAPPED *lpOverlapped,              //완료된 I/O작업에 연결된 OVERLAPPED구조체의 주소를 저장
  DWORD        dwMilliseconds              //대기시간
);

//HADNLE은 Windows API에서 사용되는 데이터 타입으로, void 포인터의 역할을 하고 여러 정보들을 저장한다.
//ULONG_PTR 부호 없는 정수형 데이터 타입으로, 64비트에서는 8바이트 크기를 가지며, 32비트에서는 4바이트 크기를 가집니다.
//PULONG_PTR ULONG_PTR의 포인터
//DWORD WindowsAPI에서 사용하는 unsigned long 자료형
