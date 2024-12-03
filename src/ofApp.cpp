#include "ofApp.h"
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

//--------------------------------------------------------------
void ofApp::setup(){
    auto glfwWindow = dynamic_cast<ofAppGLFWWindow*>(ofGetWindowPtr());
    if (glfwWindow) {
        GLFWwindow* window = glfwWindow->getGLFWWindow();
        ImGui::CreateContext();
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 150");
    }

    world = World();
    Particle* p = new Particle();
    world.addParticle(p);
}

//--------------------------------------------------------------
void ofApp::update(){
    float deltaTime = ofGetLastFrameTime() * 8;
    std::cout << deltaTime << std::endl;
    
    world.update(deltaTime);
}

//--------------------------------------------------------------
void ofApp::draw() {
    // Rendu graphique openFrameworks
    ofBackground(30, 30, 30); // Fond noir

    // D�marrer une nouvelle frame ImGui
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // Fen�tre ImGui
    ImGui::Begin("Param�tres");
    ImGui::Text("Bonjour depuis ImGui!");
    static float slider = 0.5f;
    ImGui::SliderFloat("Mon slider", &slider, 0.0f, 1.0f);
    if (ImGui::Button("Cliquez ici")) {
        ofLog() << "Bouton cliqu�!";
    }
    ImGui::End();

    // Rendu ImGui
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
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