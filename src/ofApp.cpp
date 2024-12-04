#include "ofApp.h"
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "../C_GraphicalRenderer.h"
//--------------------------------------------------------------
void ofApp::setup(){
    auto glfwWindow = dynamic_cast<ofAppGLFWWindow*>(ofGetWindowPtr());
    if (glfwWindow) {
        GLFWwindow* window = glfwWindow->getGLFWWindow();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        io.FontGlobalScale = ImGuiSize;
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 150");
    }
    world = World();

    for (int i = 0; i < 2; i++){
        Particle* p = new Particle();
        Component* graphComponent = new C_GraphicalRenderer();
        p->addComponent(graphComponent);
        world.addParticle(p);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    float deltaTime = ofGetLastFrameTime() * 8;
    std::cout << deltaTime << std::endl;
    
    world.update(deltaTime);
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackground(30, 30, 30);

    world.renderImGui(ImGuiSize);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

    //--------------------------------------------------------------
    void ofApp::exit() {
        // Nettoyage d'ImGui
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }