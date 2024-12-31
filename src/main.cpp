#include <spdlog/spdlog.h>
#include <glfw/glfw3.h>


int main(int argc, const char** argv){
    SPDLOG_INFO("start program");

    // glfw라이브러리 초기화, 실패하면 에러 출력후 종료
    SPDLOG_INFO("Initialize glfw");
    if(!glfwInit())
    {
        const char* description = nullptr;
        glfwGetError(&description);
        SPDLOG_ERROR("failed to initailize glfw: {}", description);
        return -1;
    }
    //glfw윈도우 생성, 실패하면 에러 출력후 종료료
    SPDLOG_INFO("Create glfw window");
    
        auto window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME, nullptr, nullptr);
    if(!window){
        SPDLOG_ERROR("failed to create glfw window");
        glfwTerminate();
        return -1;
    }

    //glfw 루프실행, 윈도우 close 버튼을 누르면 정상 종료
    SPDLOG_INFO("start main loop");
    while(!glfwWindowShouldClose(window)){
        glfwPollEvents();
    }
    

    glfwTerminate();
    return 0;
}

