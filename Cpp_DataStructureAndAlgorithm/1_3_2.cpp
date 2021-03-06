#include <array>
#include <iostream>
#include <type_traits>

template <typename ... Args> // 가변 템플릿
auto build_array(Args&&... args) -> std::array<typename std::common_type<Args...>::type, sizeof...(args)>
{
	using commonType = typename std::common_type<Args...>::type;
	return { std::forward<commonType>((Args&&)args)... };
}

int main()
{
	auto data = build_array(1, 0u, 'a', 3.2f, false);

	for (auto i : data)
		std::cout << i << " ";
	std::cout << std::endl;

	// 아래 코드는 하나의 공통 타입으로 변환할 수 없으므로 에러가 발생한다.
	// auto data2 = build_array(1, "Packt", 2.0);
}