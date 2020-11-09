using namespace std;

class ProgramCounter {
	public:
		/* Constructor */
		ProgramCounter();
		void set(int);
		int get();
		void toString();

	private:
		int pc;
};
