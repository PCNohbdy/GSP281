//Templatized Constructor
template<class T>
Particle<T>::Particle(Vector2 pos,float size,float vel,float angle,float life, COLORREF color)
	:T(pos,size,0,vel,angle,color)
{
	this->MaxLife = life;
	this->life = life;
	Gravity = Zero();
}
//Templatized update
template<class T>
void Particle<T>::Update(float dt)
{
	//update position
	this->Pt += this->vel;
	//update color
	this->SetColor(RGB((int)255 * (life/MaxLife), 10 * (life/MaxLife), (int)10 *(life/MaxLife)));
	//decrease life
	life -= dt;
	//rotate the particle
	++this->TextureAngle;
	//shrink the particle
	this->Scale.x = (life/MaxLife);
	this->Scale.y = (life/MaxLife);
	//set the orgion to the position
	Orgion = Pt;
	//If the Particle is dead set the collision flag to true
	if(life < 0)
	{
		this->SetCollisionFlag(true);
	}
}