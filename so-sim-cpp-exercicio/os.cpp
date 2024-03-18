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

// ---------------------------------------

void boot (Arch::Terminal *terminal, Arch::Cpu *cpu)
{
	terminal->println(Arch::Terminal::Type::Command, "Type commands here");
	terminal->println(Arch::Terminal::Type::App, "Apps output here");
	terminal->println(Arch::Terminal::Type::Kernel, "Kernel output here");
}

// ---------------------------------------

void interrupt (const Arch::InterruptCode interrupt)
{
	switch (interrupt)
	{
		case (Keyboard):
			int key_pressed = read_typed_char();
			
			if(is_backspace(key_pressed) == true){
				std::cout << _SPACE;
			}
			else if(is_alpha(key_pressed) == true){
				std::cout << static_cast<char>(key_pressed);

			}
			else if(is_num(key_pressed) == true){
				std::cout << static_cast<char>(key_pressed);
			}
			else if (is_return(key_pressed) == true){
				std::cout << std::endl; 

			}	
			break;
		case (Timer):

		case(GPF):
		default:
			break;
	}
}
	//parar de rodar o terminal
	// mostrar ao usuário 
	
	// algum momento vou ter de mostrar o que o usuário está digita}

// ---------------------------------------

void syscall ()
{

}

// ---------------------------------------

} // end namespace OS
