#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "frontend.hpp"
#include "execution_engine.hpp"

void index_loader(execution_engine* main_exec_engine)
{
    main_exec_engine->main_pager->load_index_files();
}

int main(int argc, char** argv)
{
    system("title GammaDB Engine");
    system("cls");

    EvaluationWrapper* main_io = new EvaluationWrapper();
    execution_engine* main_exec_engine = new execution_engine();
    std::cout << "Loading database indexes..." << std::endl;
    index_loader(main_exec_engine);
    std::cout << "Indexes loaded. Welcome to GammaDB." << std::endl;
    while (true)
    {
        std::cout << BLUE << DB_PROMPT << DEFAULT;
        std::getline(std::cin, InputBuffer);
        AST_NODE* eval_node = main_io->handle(InputBuffer);
        if (eval_node == nullptr)
            continue;
        main_exec_engine->execute(eval_node);
    }
    return 0;
}