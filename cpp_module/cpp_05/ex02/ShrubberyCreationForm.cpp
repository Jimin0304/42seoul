#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ): target(src.getTarget()) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if ( this != &rhs )
	{
		this->target = rhs.getTarget();
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!getIsSigned())
		throw AForm::AFormNotSignedException();
	else if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	else {
		std::string shrubbery = "        *             ,						\n"
								"					_/^\_						\n"
								"					<     >						\n"
								"	*                 /.-.\         *			\n"
								"			*        `/&\`                   *	\n"
								"					,@.*;@,						\n"
								"					/_o.I %_\    *				\n"
								"		*           (`'--:o(_@;					\n"
								"				/`;--.,__ `')             *		\n"
								"				;@`o % O,*`'`&\					\n"
								"			*    (`'--)_@ ;o %'()\      *		\n"
								"				/`;--._`''--._O'@;				\n"
								"				/&*,()~o`;-.,_ `""`)			\n"
								"	*          /`,@ ;+& () o*`;-';\				\n"
								"			(`""--.,_0 +% @' &()\				\n"
								"			/-.,_    ``''--....-'`)  *			\n"
								"		*    /@%;o`:;'--,.__   __.'\			\n"
								"			;*,&(); @ % &^;~`'`o;@();         *	\n"
								"			/(); o^~; & ().o@*&`;&%O\			\n"
								"		jgs   `"="==""==,,,.,="=='==="`			\n"
								"		__.----.(\-''#####---...___...-----._	\n"
								"		'`         \)_`"""""`					\n"
								"				.--' ')							\n"
								"			o(  )_-\							\n"
								"				`"""` `"						\n"
		//TODO::shrubbery 파일 생성
	}
}

std::string ShrubberyCreationForm::getTarget() const { return (target); }


/*
        *             ,
                       _/^\_
                      <     >
     *                 /.-.\         *
              *        `/&\`                   *
                      ,@.*;@,
                     /_o.I %_\    *
        *           (`'--:o(_@;
                   /`;--.,__ `')             *
                  ;@`o % O,*`'`&\
            *    (`'--)_@ ;o %'()\      *
                 /`;--._`''--._O'@;
                /&*,()~o`;-.,_ `""`)
     *          /`,@ ;+& () o*`;-';\
               (`""--.,_0 +% @' &()\
               /-.,_    ``''--....-'`)  *
          *    /@%;o`:;'--,.__   __.'\
              ;*,&(); @ % &^;~`"`o;@();         *
              /(); o^~; & ().o@*&`;&%O\
        jgs   `"="==""==,,,.,="=="==="`
           __.----.(\-''#####---...___...-----._
         '`         \)_`"""""`
                 .--' ')
               o(  )_-\
                 `"""` `
*/