#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <windows.h>
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
    float kat; // kat przy kolizji dla chlopaka
    float katg; // kat przy kolizji dla dziewczyny
    kat=-atan(((ball.getPosition().y+41/sqrt(2))-(c_guy.y+28/sqrt(2)))/((ball.getPosition().x+41/sqrt(2))-(c_guy.x+28/sqrt(2))));
    kat=kat*180/3.1415;
    katg=-atan(((ball.getPosition().y+41/sqrt(2))-(c_girl.y+28/sqrt(2)))/((ball.getPosition().x+41/sqrt(2))-(c_girl.x+28/sqrt(2))));
    katg=katg*180/3.1415;
    float kat_miedzy_kolami;
    //float kat_stycznej=kat_miedzy_kolami+90;
    //std::cout<<"glowa: "<<c_guy.y<<" pilka:"<<ball.getPosition().y<<std::endl;
    if(getGlobalBounds().left<=0){
        velocity_xb=fabs(velocity_xb);
        //std::cout<<velocity_xb<<std::endl;
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
        //std::cout<<"git"<<std::endl;
    }
    if((sqrt(pow(((c_guy.x+28/sqrt(2))-(ball.getPosition().x+41/sqrt(2))),2.0)+pow((c_guy.y+28/sqrt(2))-(ball.getPosition().y+41/sqrt(2)),2.0))<=98)&&last_temp==false){
        if((kat>0)&&(ball.getPosition().y+41/sqrt(2)<c_guy.y+28/sqrt(2))){ //1 cwiartka
            kat_miedzy_kolami=kat;
        }
        if((kat<0)&&(ball.getPosition().y+41/sqrt(2)<c_guy.y+28/sqrt(2))){ //2 cwiartka
           kat_miedzy_kolami=180-fabs(kat);
       }
        if((kat>0)&&(ball.getPosition().y+41/sqrt(2)>c_guy.y+28/sqrt(2))){ //3 cwiartka
           kat_miedzy_kolami=180+fabs(kat);
       }
        if((kat<0)&&(ball.getPosition().y+41/sqrt(2)>c_guy.y+28/sqrt(2))){ //4 cwiartka
           kat_miedzy_kolami=360-fabs(kat);
       }
       last_temp=true;
       sf::Vector2f srodekGlowy(c_guy.x+28/sqrt(2),c_guy.y+28/sqrt(2));
       sf::Vector2f srodekpilki(ball.getPosition().x+41/sqrt(2),ball.getPosition().y+41/sqrt(2));
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
       velocity_xb=600*cos(kat_odbicia*3.1415/180);
       velocity_y=(velocity_y*(-fabs(sin(kat_odbicia*3.1415/180)))+v_y/1.5);
       move(t*velocity_xb*18,t*velocity_y*18);
       //std::cout<<kat_odbicia<<" "<<kat_alpha<<" "<<kat_v_predkosci<<" "<<kat_miedzy_kolami<<std::endl;
       std::cout<<"detekcja"<<std::endl;
       ball.move(t*velocity_xb*18,t*velocity_y*18);
    }
    else{
        last_temp=false;
    }
    if((sqrt(pow(((c_girl.x+28.5/sqrt(2))-(ball.getPosition().x+41/sqrt(2))),2.0)+pow((c_girl.y+28.5/sqrt(2))-(ball.getPosition().y+41/sqrt(2)),2.0))<=98)&&last_tempg==false){
       // std::cout<<"kolizja"<<std::endl;
        if((katg>0)&&(ball.getPosition().y+41/sqrt(2)<c_girl.y+28/sqrt(2))){ //1 cwiartka
            kat_miedzy_kolami=kat;
        }
        if((katg<0)&&(ball.getPosition().y+41/sqrt(2)<c_girl.y+28/sqrt(2))){ //2 cwiartka
           kat_miedzy_kolami=180-fabs(kat);
       }
        if((katg>0)&&(ball.getPosition().y+41/sqrt(2)>c_girl.y+28/sqrt(2))){ //3 cwiartka
           kat_miedzy_kolami=180+fabs(kat);
       }
        if((katg<0)&&(ball.getPosition().y+41/sqrt(2)>c_girl.y+28/sqrt(2))){ //4 cwiartka
           kat_miedzy_kolami=360-fabs(kat);
       }
        last_tempg=true;
        sf::Vector2f srodekGlowy(c_girl.x+28.5/sqrt(2),c_girl.y+28.5/sqrt(2));
        sf::Vector2f srodekpilki(ball.getPosition().x+41/sqrt(2),ball.getPosition().y+41/sqrt(2));
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
        velocity_xb=600*cos(kat_odbicia*3.1415/180);
        velocity_y=(velocity_y*(-fabs(sin(kat_odbicia*3.1415/180)))+v_yg/1.5);
        move(t*velocity_xb*18,t*velocity_y*18);
        //std::cout<<kat_odbicia<<" "<<kat_alpha<<" "<<kat_v_predkosci<<" "<<kat_miedzy_kolami<<std::endl;
        //std::cout<<sin(kat_odbicia*3.1415/180)<<std::endl;
        ball.move(t*velocity_xb*18,t*velocity_y*18);
        std::cout<<"detekcja"<<std::endl;
    }
    else{
        last_tempg=false;
    }
    //std::cout<<last_tempg<<std::endl;
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
void score(sf::FloatRect coords, AnimatedSprite& pilka_, sf::CircleShape& ball_shape_,float& t){
    if(coords.top+coords.height>710){
        if(coords.left+coords.width<500){
            score_guy++;
            ball_shape_.setPosition(202,97);
            pilka_.setPosition(200,100);
            pilka_.velocity_y=0;
            pilka_.velocity_xb=0;
            pilka_.acc_y=0;
        }
        //std::cout<<score_guy;
    }
    if(t>=2.0){
        t=0;
        pilka_.velocity_y=500;
        pilka_.velocity_xb=0;
        pilka_.acc_y=400;
        //std::cout<<t;
    }
}
void score_g(sf::FloatRect coords, AnimatedSprite& pilka_, sf::CircleShape& ball_shape_,float& t){
    if(coords.top+coords.height>710){
       // std::cout<<score_girl<<" "<<coords.top+coords.height;
        if(coords.left+coords.width>530){
            score_girl++;
            ball_shape_.setPosition(702,97);
            pilka_.setPosition(700,100);
            pilka_.velocity_y=0;
            pilka_.velocity_xb=0;
            pilka_.acc_y=0;
        }
    }
    if(t>=2.0){
        t=0;
        pilka_.velocity_y=500;
        pilka_.velocity_xb=0;
        pilka_.acc_y=400;
        //std::cout<<t;
    }
}
int get_s_guy(){
    return score_guy;
}
int get_s_girl(){
    return score_girl;
}
void draw_score_guy(std::vector<sf::Sprite>numbers, sf::RenderWindow& w){
    numbers[score_guy].setPosition(975,1);
    w.draw(numbers[score_guy]);
}
void draw_score_girl(std::vector<sf::Sprite>numbers, sf::RenderWindow& w){
    numbers[score_girl].setPosition(895,1);
    w.draw(numbers[score_girl]);
}
private:
float velocity_x=500;
float velocity_y=500;
float velocity_xb=0;
sf::Vector2f last_ball_coords;
float acc_y =400;
sf::CircleShape glowa;
int score_guy=0;
int score_girl=0;
bool last_temp=false;
bool last_tempg=false;
sf::FloatRect coords_ball_;
};

void draw_triangle(sf::RenderWindow& w, sf::Vector2f coords){
    sf::ConvexShape triangle;
        triangle.setPointCount(3);
        triangle.setPoint(0, sf::Vector2f(10.0, 0.0));
        triangle.setPoint(1, sf::Vector2f(0.0, 20.0));
        triangle.setPoint(2, sf::Vector2f(20.0, 20.0));
        triangle.setOutlineColor(sf::Color::Red);
        triangle.setOutlineThickness(5);
        triangle.setPosition(coords.x+58, 10.0);
        if(coords.y<=0){
            w.draw(triangle);
        }
}
void print_score(int s_guy, int s_girl, sf::FloatRect coords){
    if(coords.top+coords.height>710){
        std::cout<<s_guy<<" : "<<s_girl<<std::endl;
    }
}

bool check_score(int s_guy, int s_girl){
    if(s_guy==5){
        std::cout<<"wygral dziewczyna"<<std::endl;
        return true;
    }
    else if (s_girl==5) {
        std::cout<<"wygral chlopak"<<std::endl;
        return true;
    }
    else{
        return false;
    }
}
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
    sf::Texture plate;
    if (!plate.loadFromFile("tabliczka.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    sf::Texture one;
    if (!one.loadFromFile("1.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    sf::Texture two;
    if (!two.loadFromFile("2.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    sf::Texture three;
    if (!three.loadFromFile("3.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    sf::Texture four;
    if (!four.loadFromFile("4.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    sf::Texture five;
    if (!five.loadFromFile("5.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    sf::Texture colon ;
    if (!colon.loadFromFile("dwukropek.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    sf::Texture null;
    if (!null.loadFromFile("0.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    sf::Texture winner_guy;
    if (!winner_guy.loadFromFile("winner_guy.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    sf::Texture winner_girl;
    if (!winner_girl.loadFromFile("winner_girl.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    AnimatedSprite tlo;
    AnimatedSprite siatka;
    AnimatedSprite guy;
    AnimatedSprite girl;
    AnimatedSprite pilka;
    sf::Sprite tabliczka;
    sf::Sprite zero;
    sf::Sprite jeden;
    sf::Sprite dwa;
    sf::Sprite trzy;
    sf::Sprite cztery;
    sf::Sprite piec;
    sf::Sprite dwukropek;
    sf::Sprite zwyciezca_chlop;
    sf::Sprite zwyciezca_dziewczyna;
    sf::Sprite temp;
    sf::CircleShape head_guy;
    sf::CircleShape head_girl;
    sf::CircleShape ball_shape;
    tabliczka.setTexture(plate);
    tabliczka.setPosition(888,1);
    dwukropek.setTexture(colon);
    dwukropek.setPosition(950,7);
    zero.setTexture(null);
    jeden.setTexture(one);
    dwa.setTexture(two);
    trzy.setTexture(three);
    cztery.setTexture(four);
    piec.setTexture(five);
    zwyciezca_chlop.setTexture(winner_guy);
    zwyciezca_dziewczyna.setTexture(winner_girl);
    std::vector<sf::Sprite>liczby;
    liczby.push_back(zero);
    liczby.push_back(jeden);
    liczby.push_back(dwa);
    liczby.push_back(trzy);
    liczby.push_back(cztery);
    liczby.push_back(piec);
    liczby.push_back(temp);
    //jeden.setPosition(888,1);
    head_guy.setRadius(40);
    head_guy.setPosition(202,570);
    head_guy.setFillColor(sf::Color(255,0,0));
    head_girl.setRadius(40);
    head_girl.setPosition(768,578);
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
    sf::FloatRect ball_coords;
    sf::Clock clock;
    float czas=0;
    float czas_s=0;
    //sf::FloatRect coords_guy;
    // run the program as long as the window is open
    while (window.isOpen()) {
        float delta=float(clock.getElapsedTime().asSeconds());
        czas+=delta;
        float v_y=guy.get_v_y();
        float v_yg=girl.get_v_y();
        //std::cout<<pilka.getGlobalBounds().top<<std::endl;

        pilka.step_ball(delta,guy.get_coords(head_guy),girl.get_coords(head_girl),ball_shape,czas,v_y,v_yg,net_coords);
        guy.step_guy(delta,head_guy);
        girl.step_girl(delta,head_girl);
        ball_coords=pilka.getGlobalBounds();
        guy.score(ball_coords,pilka,ball_shape,czas_s);
        girl.score_g(ball_coords,pilka,ball_shape,czas_s);
        print_score(guy.get_s_guy(),girl.get_s_girl(),ball_coords);
        if((pilka.getGlobalBounds().left==200&&pilka.getGlobalBounds().top==100)||(pilka.getGlobalBounds().left==700&&pilka.getGlobalBounds().top==100)){
            czas_s+=delta;
            //if(check_score(guy.get_s_guy(),girl.get_s_girl())==true){
            //    return 0;
            //}
        }
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
        window.draw(guy);
        window.draw(girl);
        window.draw(pilka);
        window.draw(tabliczka);
        window.draw(dwukropek);
        draw_triangle(window,pilka.get_coords(ball_shape));
        guy.draw_score_guy(liczby,window);
        girl.draw_score_girl(liczby,window);
        if(guy.get_s_guy()==5){
                window.draw(zwyciezca_dziewczyna);
        }
        if(girl.get_s_girl()==5){
                window.draw(zwyciezca_chlop);
        }
        if(guy.get_s_guy()>5){
            return 0;
        }
        if(girl.get_s_girl()>5){
                return 0;
        }
        //window.draw(ball_shape);
        // end the current frame
        window.display();
    }

    return 0;
}
