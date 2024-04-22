namespace nc {
	template<typename T, size_t Size>
	class array {
	public:// code
	private:
		size_t m_size = Size; T m_elements[Size]{};
	}
;

}