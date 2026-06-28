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
	//Texture = environment.water.blob; 
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
		-10,-10, -105,  70,-3,
		-10, 10, -105, 280,-3,
		 10, 10,  105, 280,-3,
		 10,-10,  105,  70,-3
	);
	QUAD(
		0,1,2,3
	);	

	HeightInfoX = [  9,  35,  -140, 140,  0,0,  0,0,  0,0,   0,0,   0,0,   0,0,    0,0,   0,0,  0,0,
						 70,  -140, 140,  0,0,  1,0,  1,-2,  1,-2,  1,1,   1,-2,   1,-2,  1,-1, 0,0, 
	                     105, -140, 140,  0,0,  1,-2, 1,-6,  1,-8,  1,-2,  1,-6,   1,-8,  1,-2, 0,0, 
	                     140, -140, 140,  0,0,  1,-2, 1,-6,  1,-10, 1,-11, 1,-9,   1,-8,  1,-2, 0,0, 
	                     175, -140, 140,  0,0,  1,-2, 1,-8,  1,-3,  1,-3,  1,-10,  1,-2,  1,0,  0,0, 
	                     210, -140, 140,  0,0,  1,1,  1,-8,  1,-10, 1,-9,  1,-10,  1,-5,  1,-2, 0,0, 
	                     245, -140, 140,  0,0,  1,-2, 1,-8,  1,-2,  1,-2,  1,-8,   1,-5,  1,-2, 0,0, 
	                     280, -140, 140,  0,0,  1,-1, 1,-1,  1,1,   1,0,   1,-2,   1,-2,  1,-1, 0,0,
	                     315, -140, 140,  0,0,  0,0,  0,0,   0,0,   0,0,   0,0,    0,0,   0,0,  0,0
	              ];


	Boundingbox = (100,-100,100,100,-100,100,-100,-100);
};
