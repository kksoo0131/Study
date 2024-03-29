# 동적 할당과 메모리 누수
포인터 변수(지역 변수)는 스택 영역에 생성된다.

동적 할당을 할 경우 해당 데이터는 힙 영역에서 메모리를 할당하고
스택 영역에 생성된 포인터 변수가 할당된 메모리를 가르킨다.

스택 영역에 있는 데이터는 함수를 기준으로 초기화 되지만
힙 영역에 있는 데이터는 프로그램이 종료될때 초기화 된다.

동적 할당된 데이터를 해제하지 않고 함수를 벗어나게되면
데이터를 가르키던 포인터 변수는 해제되고 동적 할당된 데이터는 해제되지 않으므로 접근할수가 없게된다. 
이것을 메모리 누수라고한다.


해결방법은 함수를 벗어나기전에 포인터 변수가 가르키고 있는 동적할당된 메모리를
delete() 함수를 이용해 해제해줘야한다.

# 스마트 포인터
C++ 11 이상의 표준에서 제공된다.

동적 할당 메모리를 자동으로 해제해준다.

std 네임스페이스 : unique_ptr, shared_ptr, weak_ptr 

# unique_ptr
특정 객체를 하나의 스마트 포인터만이 가리킬 수 있게한다.

```cpp
#include <iostream>
int main(){
  std::unique_ptr<int> ptr1(new int(5));
  auto ptr2 = std::make_unique<int>(10);

  // 특정 객체를 하나의 스마트 포인터만이 가리킬수 있기 때문에 복사 생성자를 가지지 않고 
  // auto ptr3 = ptr1; 와 같은 대입 형태는 지원하지 않는다.

  auto ptr3 = move(ptr1);
  //move() 함수를 통해서 특정 객체의 소유권을 이전할 수 있다.
  //이경우 이전한 유니크 포인터는 아무것도 가리키는 것이 없고 소멸한 포인터로 취급된다.

  // make_unique() 함수를 통해서는 배열 형태의 유니크 포인터를 초기화 할수 없다. ( 배열이 생성되기는 한다.) 
}
```
