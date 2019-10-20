//
// Created by dobrowol on 16.10.2019.
//

#ifndef MOVIETHEATER_COMMAND_H
#define MOVIETHEATER_COMMAND_H


#include <string>
#include <vector>

class Command {
public:
/**
* \brief   The execute function.
*
* \details This function executes command from client. Its input is vector of parameters
*          and output is result of executing command.
*   .
*
*
* \param[in]     args    arguments stored in vector of strings.
*
* \return        Return result of execution. Might be true or false.
*
* \retval        true    The command is successfully executed. It does not mean that it is finished with success.
* \retval        false   Error during input check of arguments invalidation cause that command was not executed.
*/
    virtual bool execute(std::vector<std::string> args) = 0;

    /**
* \brief   The check of input function.
*
* \details This function checks if argument number and format are proper for this command.
*   .
*
*
* \param[in]     args    arguments stored in vector of strings.
*
* \return        Return result of checking the validity. Might be true or false.
*
* \retval        true    Parameters were valid.
* \retval        false   Format or number of arguments is invalid.
*/
    virtual bool inputCheck(std::vector<std::string> args) = 0;
};


#endif //MOVIETHEATER_COMMAND_H
