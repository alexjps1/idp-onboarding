define SIG3DObject Lake
{
	Animation = water; 
	AnimationType = SIG_ANIMATION_ALWAYS; 
	
	Translate = <0,0,0>;
	Rotate = <0,0,0>;
	Scale = <1,1,1>;
	Color = (0.2,0.1,0.05,0.3);
	//Color = (1,1,1,1); 
	Texture = environment.water.wave_tm_h1; 
	TextureFilter = RepeatS | RepeatT | MagLinear | MinLinearMipMapNearest | TextureMipMap | NoCompression;
	Texture[1] = $Environment; 
	Culling = CCW; 
	Storage = Component; 
	PixelShader = Water; 
	VertexShader = Water; 
	
	RenderClass = Transparent; 
	Blend = true; 
	AlphaTest = 0.02; 
	Storage = Component; 
	
	define Cookies {
		vx = 0.1; 
		vy = 0.01; 
	}; 
	
	Shader {
		ReflectionAmount = [0.8, 0.3]; 
		Roughness = 0.15; 
		WaveScale = [10, 10]; 
		WaveOffset = [0, 0]; 
		SpecularPower = 200; 
	}; 
	
	TV(
		-14,-20, -140,-200,-14,
		-14, 20, -140, 200,-14,
		 14, 20,  140, 200,-14,
		 14,-20,  140,-200,-14
	);
	QUAD(
		0,1,2,3
	);	
	
	Boundingbox = (100,-150,100,200,-140,200,-140,-150);
	
};
