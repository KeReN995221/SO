#include <stdexcept>
#include <string>
#include <string_view>

#include <cstdint>
#include <cstdlib>

#include "config.h"
#include "lib.h"
#include "arq-sim.h"
#include "os.h"


namespace OS {
	Arch::Terminal *terminal;
	std::vector<int> mensagem;
// ---------------------------------------

void boot (Arch::Terminal *terminal, Arch::Cpu *cpu)
{
	OS::terminal = terminal;
	terminal->println(Arch::Terminal::Type::Command, "Type commands here");
	terminal->println(Arch::Terminal::Type::App, "Apps output here");
	terminal->println(Arch::Terminal::Type::Kernel, "Kernel output here");
}

// ---------------------------------------

void interrupt (const Arch::InterruptCode interrupt)
{
	if(interrupt == Arch::InterruptCode::Keyboard){
		int teclado = terminal->read_typed_char();

		if(terminal->is_backspace(teclado)){
			mensagem.pop_back();
			terminal->print(Arch::Terminal::Type::Kernel, "\r");
			for(int i = 0; i < mensagem.size(); i++){
				terminal->print(Arch::Terminal::Type::Kernel, static_cast <char> (mensagem[i]));
			}
		}else if(terminal->is_alpha(teclado)){
			mensagem.push_back(teclado);
			terminal->print(Arch::Terminal::Type::Kernel, static_cast <char> (teclado));
		}
		else if(terminal->is_num(teclado)){
			mensagem.push_back(teclado);
			terminal->print(Arch::Terminal::Type::Kernel, static_cast <char> (teclado));
		}
		else if(terminal->is_return(teclado)){
			mensagem.clear();
			terminal->print(Arch::Terminal::Type::Kernel, "\n");
		}
	}
}


// ---------------------------------------

void syscall ()
{

}

// ---------------------------------------

} // end namespace OS
