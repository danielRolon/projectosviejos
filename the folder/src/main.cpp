#include <iostream>
#include <string.h>

class String {
public:
	String(const char* string) {
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, string, m_Size);
		m_Buffer[m_Size] = 0;

	}

	String(const String& other)
		: m_Size(other.m_Size) {
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
	}

	~String() {
		if (m_Buffer) {
			delete[] m_Buffer;
			m_Buffer = nullptr;
		}
	}

	char& operator[](uint32_t index) {
		return m_Buffer[index];
	}

	const char* GetBuffer() const {
		return m_Buffer;
	}
private:
	char* m_Buffer { nullptr };
	uint32_t m_Size = 0;
};

std::ostream& operator<<(std::ostream& stream, const String& string) {
	stream << string.GetBuffer();
	return stream;
}

int main() {

	String a = "narCa";
	String b = a;
	b[1] = 'o';
	std::cout << a << "\n";
	std::cout << b << "\n";

	return 0;
}