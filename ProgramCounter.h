using namespace std;

class ProgramCounter {
	public:
		/* Constructor */
		ProgramCounter();
		void set(string);
		int get();
		void toString();

	private:
		int pc;
};
