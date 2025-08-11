#include <iostream>

int main(int argc, char* argv[]){

    std::cout << "argc: " << argc << std::endl;
    if(argc < 2){
        
    }     
    

    for(int i=0; i < argc; i++){
        std::cout << "[" << i << "]" << argv[i] << std::endl;
    }
    return 0;
}
