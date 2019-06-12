#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>
class AnimatedSprite:public sf::Sprite{
public:
AnimatedSprite(): sf::Sprite(){}
void step_guy(float t, sf::CircleShape &head){
    velocity_y+=t*acc_y;
    if(getGlobalBounds().left+getGlobalBounds().width<=550){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        move(velocity_x*t,0);
        head.move(velocity_x*t,0);
    }
    }
    if(getGlobalBounds().left>=0){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            move(-velocity_x*t,0);
            head.move(-velocity_x*t,0);
        }
    }
    if(getGlobalBounds().top+getGlobalBounds().height<719){
        move(0,t*velocity_y);
        head.move(0,t*velocity_y);
    }
    else {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            velocity_y=-500;
                move(0,t*velocity_y);
                head.move(0,t*velocity_y);
            }
        else {
             velocity_y=0;
        }
    }
}
void step_girl(float t,sf::CircleShape &head){
    velocity_y+=t*acc_y;
    //std::cout<<head.getPosition().x<<"  "<<head.getPosition().y<<std::endl;
    if(getGlobalBounds().left+getGlobalBounds().width<=1050){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        move(velocity_x*t,0);
        head.move(velocity_x*t,0);
    }
    }
    if(getGlobalBounds().left>=550){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            move(-velocity_x*t,0);
            head.move(-velocity_x*t,0);
        }
    }
    if(getGlobalBounds().top+getGlobalBounds().height<705){
        move(0,t*velocity_y);
        head.move(0,t*velocity_y);
    }
    else {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            velocity_y=-500;
                move(0,t*velocity_y);
                head.move(0,t*velocity_y);
            }
        else {
               velocity_y=0;
        }

    }
}
void step_ball(float t,sf::Vector2f c_guy, sf::Vector2f c_girl, sf::CircleShape &ball, float &czas, const float& v_y, const float& v_yg,sf::FloatRect n_coords){
    velocity_y+=t*acc_y;
    coords_ball_=getGlobalBounds();
    float velocity_value_b;
    float kat;
    float katg;
    kat=-atan(((ball.getPosition().y+41/sqrt(2))-(c_guy.y+28/sqrt(2)))/((ball.getPosition().x+41/sqrt(2))-(c_guy.x+28/sqrt(2))));
    kat=kat*180/3.1415;
    katg=-atan(((ball.getPosition().y+41/sqrt(2))-(c_girl.y+28/sqrt(2)))/((ball.getPosition().x+41/sqrt(2))-(c_girl.x+28/sqrt(2))));
    katg=katg*180/3.1415;
    float kat_miedzy_kolami;
    float kat_stycznej=kat_miedzy_kolami+90;
    if(getGlobalBounds().left<=0){
        velocity_xb=fabs(velocity_xb);
        std::cout<<velocity_xb<<std::endl;
    }
    if(getGlobalBounds().left+getGlobalBounds().width>=1024){
        velocity_xb=-fabs(velocity_xb);
    }
    if(getGlobalBounds().top+getGlobalBounds().height<710){
        move(t*velocity_xb,t*velocity_y);
        ball.move(t*velocity_xb,t*velocity_y);
    }
    if((n_coords.left<getGlobalBounds().left+getGlobalBounds().width)&&n_coords.top<getGlobalBounds().top+getGlobalBounds().height&&n_coords.left+20>getGlobalBounds().left+getGlobalBounds().width){
        velocity_xb=-fabs(velocity_xb);
        //std::cout<<"git"<<std::endl;
    }
    if(((n_coords.left+n_coords.width)>getGlobalBounds().left)&&n_coords.top<getGlobalBounds().top+getGlobalBounds().height&&n_coords.left+n_coords.width-20<getGlobalBounds().left){
        velocity_xb=fabs(velocity_xb);
    }
    if((n_coords.top<getGlobalBounds().top+getGlobalBounds().height)&&n_coords.left-45<getPosition().x+41/sqrt(2)&&getPosition().x+41/sqrt(2)<n_coords.left+n_coords.width+20){
        velocity_y=-fabs(velocity_y);
        std::cout<<"git"<<std::endl;
    }
    if((sqrt(pow(((c_guy.x+28/sqrt(2))-(ball.getPosition().x+41/sqrt(2))),2.0)+pow((c_guy.y+28/sqrt(2))-(ball.getPosition().y+41/sqrt(2)),2.0))<=98)&&czas>0.4){
       if(kat<0){
           kat_miedzy_kolami=90-fabs(kat)+90;
       }
       else {
           kat_miedzy_kolami=kat;
       }
       sf::Vector2f srodekGlowy(c_guy.x+28/sqrt(2),c_guy.y+28/sqrt(2));
       sf::Vector2f srodekpilki(ball.getPosition().x+41/sqrt(2),ball.getPosition().y+28/sqrt(2));
       float kat_v_predkosci=-atan(((last_ball_coords.y+41/sqrt(2))-(ball.getPosition().y+41/sqrt(2)))/((last_ball_coords.x+41/sqrt(2))-(ball.getPosition().x+41/sqrt(2))));
       czas=0;
       kat_v_predkosci=kat_v_predkosci*180/3.1415;
       if(kat_v_predkosci<0){
          kat_v_predkosci=90-fabs(kat_v_predkosci)+90;
       }
       float kat_alpha=kat_v_predkosci-kat_miedzy_kolami;
       kat_alpha=fabs(kat_alpha);
       float kat_odbicia=kat_miedzy_kolami-kat_alpha;
       if(kat_miedzy_kolami>90){
           kat_odbicia=kat_miedzy_kolami+kat_alpha;
       }
       velocity_xb=500*cos(kat_odbicia*3.1415/180);
       velocity_y=(velocity_y*(-fabs(sin(kat_odbicia*3.1415/180)))+v_y/2);
       move(t*velocity_xb*15,t*velocity_y*15);
       std::cout<<kat_odbicia<<" "<<kat_alpha<<" "<<kat_v_predkosci<<" "<<kat_miedzy_kolami<<std::endl;
       std::cout<<sin(kat_odbicia*3.1415/180)<<std::endl;
       ball.move(t*velocity_xb*15,t*velocity_y*15);
    }
    if((sqrt(pow(((c_girl.x+28/sqrt(2))-(ball.getPosition().x+41/sqrt(2))),2.0)+pow((c_girl.y+28/sqrt(2))-(ball.getPosition().y+41/sqrt(2)),2.0))<=98)&&czas>0.4){
        std::cout<<"kolizja"<<std::endl;
        if(katg<0){
            kat_miedzy_kolami=90-fabs(katg)+90;
        }
        else {
            kat_miedzy_kolami=katg;
        }
        sf::Vector2f srodekGlowy(c_girl.x+28/sqrt(2),c_girl.y+28/sqrt(2));
        sf::Vector2f srodekpilki(ball.getPosition().x+41/sqrt(2),ball.getPosition().y+28/sqrt(2));
        float kat_v_predkosci=-atan(((last_ball_coords.y+41/sqrt(2))-(ball.getPosition().y+41/sqrt(2)))/((last_ball_coords.x+41/sqrt(2))-(ball.getPosition().x+41/sqrt(2))));
        czas=0;
        kat_v_predkosci=kat_v_predkosci*180/3.1415;
        if(kat_v_predkosci<0){
           kat_v_predkosci=90-fabs(kat_v_predkosci)+90;
        }
        float kat_alpha=kat_v_predkosci-kat_miedzy_kolami;
        kat_alpha=fabs(kat_alpha);
        float kat_odbicia=kat_miedzy_kolami-kat_alpha;
        if(kat_miedzy_kolami>90){
            kat_odbicia=kat_miedzy_kolami+kat_alpha;
        }
        velocity_xb=500*cos(kat_odbicia*3.1415/180);
        velocity_y=(velocity_y*(-fabs(sin(kat_odbicia*3.1415/180)))+v_yg/2);
        move(t*velocity_xb*15,t*velocity_y*15);
        std::cout<<kat_odbicia<<" "<<kat_alpha<<" "<<kat_v_predkosci<<" "<<kat_miedzy_kolami<<std::endl;
        std::cout<<sin(kat_odbicia*3.1415/180)<<std::endl;
        ball.move(t*velocity_xb*15,t*velocity_y*15);
    }
    //std::cout<<kat_v_predkosci<<std::endl;
    last_ball_coords=sf::Vector2f(ball.getPosition().x,ball.getPosition().y);
}
sf::Vector2f get_coords(sf::CircleShape&head){
    sf::Vector2f pom=head.getPosition();
    return pom;
}
float get_v_y(){
    float temp=velocity_y;
    return temp;
}
private:
float velocity_x=500;
float velocity_y=500;
float velocity_xb=0;
sf::Vector2f last_ball_coords;
float acc_y =400;
sf::CircleShape glowa;
sf::FloatRect coords_ball_;
};

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(1024, 768), "My window");
    sf::Texture background;
    if (!background.loadFromFile("tlo.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    sf::Texture net;
    if (!net.loadFromFile("siatkad.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    sf::Texture player;
    if (!player.loadFromFile("Idle (1)a.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    sf::Texture player2;
    if (!player2.loadFromFile("Idle (1)b.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    sf::Texture ball;
    if (!ball.loadFromFile("ball.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    AnimatedSprite tlo;
    AnimatedSprite siatka;
    AnimatedSprite guy;
    AnimatedSprite girl;
    AnimatedSprite pilka;
    sf::CircleShape head_guy;
    sf::CircleShape head_girl;
    sf::CircleShape ball_shape;
    head_guy.setRadius(40);
    head_guy.setPosition(202,570);
    head_guy.setFillColor(sf::Color(255,0,0));
    head_girl.setRadius(40);
    head_girl.setPosition(770,578);
    head_girl.setFillColor(sf::Color(255,0,0));
    ball_shape.setRadius(58);
    ball_shape.setPosition(202,97);
    ball_shape.setFillColor(sf::Color(255,0,0));
    tlo.setTexture(background);
    siatka.setTexture(net);
    siatka.setPosition(490,390);
    guy.setTexture(player);
    guy.setPosition(200,550);
    girl.setTexture(player2);
    girl.setPosition(754,570);
    pilka.setTexture(ball);
    pilka.setPosition(200,100);
    sf::FloatRect net_coords=siatka.getGlobalBounds();
    sf::Clock clock;
    float czas=0;
    //sf::FloatRect coords_guy;
    // run the program as long as the window is open
    while (window.isOpen()) {
        float delta=float(clock.getElapsedTime().asSeconds());
        czas+=delta;
        float v_y=guy.get_v_y();
        float v_yg=girl.get_v_y();
        pilka.step_ball(delta,guy.get_coords(head_guy),girl.get_coords(head_girl),ball_shape,czas,v_y,v_yg,net_coords);
        guy.step_guy(delta,head_guy);
        girl.step_girl(delta,head_girl);
        //pilka.colisions(guy.get_coords(),girl.get_coords());
        clock.restart();
        //coords_guy = guy.getGlobalBounds();
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(tlo);
        window.draw(siatka);
        //window.draw(head_guy);
        //window.draw(head_girl);
        window.draw(guy);
        window.draw(girl);
        window.draw(pilka);
        //window.draw(ball_shape);
        // end the current frame
        window.display();
    }

    return 0;
}
