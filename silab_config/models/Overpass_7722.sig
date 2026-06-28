define SIG3DObject Overpass
{
	Animation = Area2Animation;
	AnimationType = SIG_ANIMATION_ONESHOT;
	AlphaTest = 0.200000;
	Color = (1.000000,1.000000,1.000000,1.000000);
	Culling = CCW;
	DepthTest = 1;
	Fog = 1;
	Translate = <0,0,0>;
	Rotate = <0,0,0>;
	Scale = <1,1,1>;
	RenderClass = ZBuffered;
	ShadeMode = Smooth;
	Show = true;
	VisTest = true;
	Blend = false;
	SubObject BorderStrip0
	{
		AlphaTest = 0.200000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		Texture = area2.curbstone;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 3;
		Storage = Component;
		TVN(
			0, 0, -16.2428, -4.33198, 0.01, 0.707099, -0.00342168, 0.707107,
			0, 0.1, -16.2628, -4.33189, 0.03, 0.707099, -0.00342168, 0.707107,
			9.76563, 0, -16.1955, 5.43353, 0.01, 0.707099, -0.00342168, 0.707107,
			9.76563, 0.1, -16.2155, 5.43363, 0.03, 0.707099, -0.00342168, 0.707107
		);
		TRI(
			3, 0, 1,
			3, 2, 0
		);
	};
	SubObject BorderStrip0_Top
	{
		AlphaTest = 0.200000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		Texture = scnx.road.pavings.grass_area;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 1;
		Texture[1] = scnx.road.pavings.grass_area_nrm;
		TextureFilter[1] = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel[1] = 0;
		TextureMaxLevel[1] = 1000;
		TextureMaxLod[1] = 1000;
		TextureMinLod[1] = -1000;
		TextureAnisotropy[1] = 1;
		TangentSpace = true;
		PixelShader = Tex0NormalMap1;
		Storage = Component;
		TVN(
			0.264168, 0.00108989, -18.0144, 5.44233, 0.03, 0, 0, 1,
			0.000234356, 0, -18.0547, -4.32321, 0.03, 0, 0, 1,
			0, 0.0484302, -16.2628, -4.33189, 0.03, 0, 0, 1,
			0.263933, 0.0497073, -16.2155, 5.43363, 0.03, 0, 0, 1
		);
		TRI(
			3, 1, 0,
			3, 2, 1
		);
	};
	SubObject BorderStrip0_Shoulder
	{
		AlphaTest = 0.500000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		TangentSpace = true;
		PixelShader = Tex0NormalMap1;
		Texture = scnx.road.pavings.grass_area;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 1;
		Texture[1] = scnx.road.pavings.grass_area_nrm;
		TextureFilter[1] = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel[1] = 0;
		TextureMaxLevel[1] = 1000;
		TextureMaxLod[1] = 1000;
		TextureMinLod[1] = -1000;
		TextureAnisotropy[1] = 1;
		Storage = Buffer;
		TV(
			-1.30784e-06, 0.0487004, -16.2528, -4.33193, 0.03,
			-0.0394603, 0.0485095, -16.2598, -5.79192, -0.7,
			0.000234356, 0, -18.0547, -4.32321, 0.03,
			-0.0194137, -0.019825, -18.7882, -5.05019, -0.7,
			0.264168, 0.00108989, -18.0144, 5.44233, 0.03,
			0.283979, -0.0185442, -18.7408, 6.17534, -0.7,
			0.263931, 0.0499776, -16.2055, 5.43358, 0.03,
			0.30339, 0.0501686, -16.1985, 6.89356, -0.7 
		);
		STRIP(
			0, 			1, 			2, 			3, 			4, 			5, 			6, 			7 
		);
	};
	SubObject BorderStrip1
	{
		AlphaTest = 0.200000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		Texture = area2.curbstone;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 3;
		Storage = Component;
		TVN(
			0, 0, 6.78421, 5.32233, 0.01, -0.707099, 0.00342168, 0.707107,
			0, 0.1, 6.80421, 5.32223, 0.03, -0.707099, 0.00342168, 0.707107,
			9.76563, 0, 6.73695, -4.44318, 0.01, -0.707099, 0.00342168, 0.707107,
			9.76563, 0.1, 6.75695, -4.44328, 0.03, -0.707099, 0.00342168, 0.707107
		);
		TRI(
			3, 0, 1,
			3, 2, 0
		);
	};
	SubObject BorderStrip1_Top
	{
		AlphaTest = 0.200000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		Texture = scnx.road.pavings.grass_area;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 1;
		Texture[1] = scnx.road.pavings.grass_area_nrm;
		TextureFilter[1] = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel[1] = 0;
		TextureMaxLevel[1] = 1000;
		TextureMaxLod[1] = 1000;
		TextureMinLod[1] = -1000;
		TextureAnisotropy[1] = 1;
		TangentSpace = true;
		PixelShader = Tex0NormalMap1;
		Storage = Component;
		TVN(
			0, 0.0480081, 8.53325, -4.45187, 0.03, 0, 0, 1,
			0.263932, 0.0495344, 8.58973, 5.31359, 0.03, 0, 0, 1,
			0.264165, 0.00127718, 6.80421, 5.32223, 0.03, 0, 0, 1,
			0.000232313, 0, 6.75695, -4.44328, 0.03, 0, 0, 1
		);
		TRI(
			3, 2, 0,
			2, 1, 0
		);
	};
	SubObject BorderStrip1_Shoulder
	{
		AlphaTest = 0.500000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		TangentSpace = true;
		PixelShader = Tex0NormalMap1;
		Texture = scnx.road.pavings.grass_area;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 1;
		Texture[1] = scnx.road.pavings.grass_area_nrm;
		TextureFilter[1] = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel[1] = 0;
		TextureMaxLevel[1] = 1000;
		TextureMaxLod[1] = 1000;
		TextureMinLod[1] = -1000;
		TextureAnisotropy[1] = 1;
		Storage = Buffer;
		TV(
			0.264166, 0.00100692, 6.79421, 5.32228, 0.03,
			0.303625, 0.00119786, 6.80127, 6.78227, -0.7,
			0.263932, 0.0495344, 8.58973, 5.31359, 0.03,
			0.283547, 0.0693593, 9.32325, 6.03936, -0.7,
			0, 0.0480081, 8.53325, -4.45187, 0.03,
			-0.0198436, 0.067642, 9.25971, -5.18609, -0.7,
			0.000233621, -0.000270267, 6.74695, -4.44323, 0.03,
			-0.0392254, -0.000461211, 6.73989, -5.90321, -0.7 
		);
		STRIP(
			0, 			1, 			2, 			3, 			4, 			5, 			6, 			7 
		);
	};
	SubObject BorderStrip2
	{
		AlphaTest = 0.200000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		Texture = area2.curbstone;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 3;
		Storage = Component;
		TVN(
			0, 0, -58.5962, 9.1611, 4.01, -0.182462, -0.683884, 0.706407,
			0, 0.1, -58.5926, 9.18077, 4.03, -0.182511, -0.68425, 0.706039,
			31.4097, 0, -28.2811, 3.63787, 6.01, -0.030456, -0.706716, 0.706842,
			31.4097, 0.1, -28.281, 3.65787, 6.03, -0.0304557, -0.706601, 0.706957,
			4.12132, 0, -54.4579, 8.31499, 4.2598, -0.201543, -0.678483, 0.70629,
			4.12132, 0.1, -54.4536, 8.33452, 4.2798, -0.192022, -0.68132, 0.706211,
			8.24264, 0, -50.3935, 7.37499, 4.57512, -0.218816, -0.673574, 0.705964,
			8.24264, 0.1, -50.3889, 7.39445, 4.59512, -0.214967, -0.674806, 0.70597,
			12.364, 0, -46.3869, 6.41339, 4.92302, -0.219151, -0.673681, 0.705776,
			12.364, 0.1, -46.3822, 6.43285, 4.94302, -0.220907, -0.672997, 0.705881,
			16.4853, 0, -42.422, 5.49893, 5.27057, -0.202309, -0.678833, 0.705786,
			16.4853, 0.1, -42.4177, 5.51847, 5.29057, -0.209822, -0.676343, 0.705983,
			20.6066, 0, -38.486, 4.6991, 5.58486, -0.167479, -0.687854, 0.705983,
			20.6066, 0.1, -38.4824, 4.71878, 5.60486, -0.18109, -0.684134, 0.706239,
			24.7279, 0, -34.5722, 4.08153, 5.83294, -0.113599, -0.698154, 0.706289,
			24.7279, 0.1, -34.5696, 4.10137, 5.85294, -0.13369, -0.694333, 0.706538,
			28.8492, 0, -30.6819, 3.71321, 5.98188, -0.051467, -0.705036, 0.706673,
			28.8492, 0.1, -30.6808, 3.73318, 6.00188, -0.0724628, -0.7031, 0.706761
		);
		TRI(
			7, 4, 5,
			5, 4, 0,
			16, 3, 2,
			5, 0, 1,
			7, 6, 4,
			9, 6, 7,
			9, 8, 6,
			11, 8, 9,
			11, 10, 8,
			13, 10, 11,
			13, 12, 10,
			15, 12, 13,
			15, 14, 12,
			17, 14, 15,
			17, 16, 14,
			17, 3, 16
		);
	};
	SubObject BorderStrip2_Top
	{
		AlphaTest = 0.200000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		Texture = scnx.road.pavings.grass_area;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 1;
		Texture[1] = scnx.road.pavings.grass_area_nrm;
		TextureFilter[1] = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel[1] = 0;
		TextureMaxLevel[1] = 1000;
		TextureMaxLod[1] = 1000;
		TextureMinLod[1] = -1000;
		TextureAnisotropy[1] = 1;
		TangentSpace = true;
		PixelShader = Tex0NormalMap1;
		Storage = Component;
		TVN(
			0.144214, 0.211302, -50.7744, 8.99379, 4.53527, -0.0765572, 0.0120996, 0.99692,
			0.192454, 0.0079939, -58.2968, 10.7787, 4.03, -0.0631755, 0.0026563, 0.997953,
			0.0858356, 0.458329, -41.6344, 6.83379, 5.3309, -0.0776071, 0.019571, 0.996761,
			0.0550248, 0.643735, -34.7744, 5.69378, 5.83078, -0.0492848, 0.0171758, 0.998456,
			0.0462059, 0.819434, -28.2735, 5.36748, 6.03, -0.0205158, 0.0130208, 0.999582,
			0.149268, 0, -58.5926, 9.18077, 4.03, -0.0580509, 0.0107453, 0.998256,
			0, 0.819232, -28.281, 3.65787, 6.03, -0.0117146, 5.10945e-05, 0.999931,
			0.126396, 0.111864, -54.4536, 8.33452, 4.2798, -0.0663773, 0.00835998, 0.997686,
			0.100989, 0.221722, -50.3889, 7.39445, 4.59512, -0.0775598, 0.0186023, 0.996802,
			0.0749995, 0.330009, -46.3822, 6.43285, 4.94302, -0.0827141, 0.017647, 0.996417,
			0.0502865, 0.437159, -42.4177, 5.51847, 5.29057, -0.0797798, 0.0169538, 0.996661,
			0.0286732, 0.543518, -38.4824, 4.71878, 5.60486, -0.0689921, 0.0162167, 0.997428,
			0.0119866, 0.649268, -34.5696, 4.10137, 5.85294, -0.0498813, 0.00748136, 0.998648,
			0.00203537, 0.754373, -30.6808, 3.73318, 6.00188, -0.0261475, 0.0117116, 0.999474
		);
		TRI(
			13, 3, 4,
			7, 1, 0,
			11, 2, 3,
			13, 4, 6,
			9, 0, 2,
			8, 7, 0,
			7, 5, 1,
			9, 8, 0,
			10, 9, 2,
			11, 10, 2,
			12, 11, 3,
			13, 12, 3
		);
	};
	SubObject BorderStrip2_Shoulder
	{
		AlphaTest = 0.500000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		TangentSpace = true;
		PixelShader = Tex0NormalMap1;
		Texture = scnx.road.pavings.grass_area;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 1;
		Texture[1] = scnx.road.pavings.grass_area_nrm;
		TextureFilter[1] = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel[1] = 0;
		TextureMaxLevel[1] = 1000;
		TextureMaxLod[1] = 1000;
		TextureMinLod[1] = -1000;
		TextureAnisotropy[1] = 1;
		Storage = Buffer;
		TV(
			0.149002, -4.91916e-05, -58.5944, 9.17093, 4.03,
			0.195537, -0.251454, -67.8964, 10.8927, -0.7,
			0.192454, 0.0079939, -58.2968, 10.7787, 4.03,
			0.340106, -0.0881951, -61.8558, 16.2418, -0.7,
			0.144214, 0.211302, -50.7744, 8.99379, 4.53527,
			0.419586, 0.27651, -48.3617, 19.1826, -0.7,
			0.0858356, 0.458329, -41.6344, 6.83379, 5.3309,
			0.405256, 0.522537, -39.2587, 18.6523, -0.7,
			0.0550248, 0.643735, -34.7744, 5.69378, 5.83078,
			0.40543, 0.681519, -33.3764, 18.6588, -0.7,
			0.0462059, 0.819434, -28.2735, 5.36748, 6.03,
			0.227076, 1.01044, -21.2062, 12.0597, -0.7,
			-0.000270268, 0.819231, -28.281, 3.64787, 6.03,
			-0.00185694, 1.18301, -14.8212, 3.58916, -0.7 
		);
		STRIP(
			0, 			1, 			2, 			3, 			4, 			5, 			6, 			7,
			8, 			9, 			10, 			11, 			12, 			13  		);
	};
	SubObject BorderStrip3
	{
		AlphaTest = 0.200000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		Texture = area2.curbstone;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 3;
		Storage = Component;
		TVN(
			0, 0, -28.3072, -2.34208, 6.01, 0.0202877, 0.707109, 0.706813,
			0, 0.1, -28.3072, -2.36208, 6.03, 0.0202784, 0.706921, 0.707002,
			31.4097, 0, -59.6846, 3.28099, 4.01, 0.0969197, 0.700804, 0.706739,
			31.4097, 0.1, -59.6883, 3.26132, 4.03, 0.0969835, 0.701063, 0.706473,
			3.82321, 0, -32.3545, -2.16474, 5.94875, 0.0411275, 0.706241, 0.706622,
			3.82321, 0.1, -32.3561, -2.18468, 5.96875, 0.0306827, 0.706487, 0.706907,
			7.94453, 0, -36.6426, -1.66852, 5.76593, 0.0681301, 0.704565, 0.706264,
			7.94453, 0.1, -36.6456, -1.68831, 5.78593, 0.0597856, 0.70489, 0.706695,
			12.0659, 0, -40.8428, -0.939802, 5.49407, 0.0879033, 0.70273, 0.705958,
			12.0659, 0.1, -40.8466, -0.959427, 5.51407, 0.0820897, 0.703029, 0.70636,
			16.1872, 0, -44.9597, -0.0609768, 5.16609, 0.100371, 0.701246, 0.705803,
			16.1872, 0.1, -44.9641, -0.0804786, 5.18609, 0.0969501, 0.701482, 0.706046,
			20.3085, 0, -49.0069, 0.891749, 4.81493, 0.10603, 0.700375, 0.705854,
			20.3085, 0.1, -49.0116, 0.872303, 4.83493, 0.104863, 0.700529, 0.705876,
			24.4298, 0, -53.0008, 1.84734, 4.47352, 0.105226, 0.700239, 0.70611,
			24.4298, 0.1, -53.0054, 1.82787, 4.49352, 0.106227, 0.700286, 0.705913,
			28.5511, 0, -56.9568, 2.73757, 4.17477, 0.0993844, 0.700727, 0.706465,
			28.5511, 0.1, -56.961, 2.718, 4.19477, 0.10186, 0.700659, 0.706179
		);
		TRI(
			5, 0, 1,
			5, 4, 0,
			7, 4, 5,
			7, 6, 4,
			9, 6, 7,
			9, 8, 6,
			11, 8, 9,
			13, 10, 11,
			11, 10, 8,
			13, 12, 10,
			16, 3, 2,
			15, 12, 13,
			15, 14, 12,
			17, 14, 15,
			17, 16, 14,
			17, 3, 16
		);
	};
	SubObject BorderStrip3_Top
	{
		AlphaTest = 0.200000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		Texture = scnx.road.pavings.grass_area;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 1;
		Texture[1] = scnx.road.pavings.grass_area_nrm;
		TextureFilter[1] = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel[1] = 0;
		TextureMaxLevel[1] = 1000;
		TextureMaxLod[1] = 1000;
		TextureMinLod[1] = -1000;
		TextureAnisotropy[1] = 1;
		TangentSpace = true;
		PixelShader = Tex0NormalMap1;
		Storage = Component;
		TVN(
			0.0173531, 0.640518, -36.2944, -3.44621, 5.8171, -0.0509202, -0.00516326, 0.998441,
			0, 0.856183, -28.3148, -4.08828, 6.03, -0.0220762, -0.0147094, 0.999515,
			0.0584342, 0.414031, -44.6744, -1.92621, 5.24224, -0.0771189, 0.0123739, 0.996878,
			0.106542, 0.201059, -52.5544, -0.146217, 4.56583, -0.0744314, 0.0217361, 0.996955,
			0.154063, 0, -59.9936, 1.61204, 4.03, -0.0615358, 0.0200644, 0.997854,
			0.0466541, 0.856387, -28.3072, -2.36208, 6.03, -0.0151222, 6.59571e-05, 0.999886,
			0.198638, 0.00825087, -59.6883, 3.26132, 4.03, -0.0581664, 0.0107666, 0.998249,
			0.0514486, 0.746958, -32.3561, -2.18468, 5.96875, -0.0285479, -0.00666523, 0.999375,
			0.064864, 0.631027, -36.6456, -1.68831, 5.78593, -0.0526058, 0.00719269, 0.998525,
			0.0845635, 0.517485, -40.8466, -0.959427, 5.51407, -0.0695424, 0.00596379, 0.997501,
			0.108319, 0.406201, -44.9641, -0.0804786, 5.18609, -0.0789145, 0.0179338, 0.996714,
			0.13407, 0.29681, -49.0116, 0.872303, 4.83493, -0.0814825, 0.0181982, 0.996508,
			0.159896, 0.18887, -53.0054, 1.82787, 4.49352, -0.0758066, 0.0192002, 0.996924,
			0.183954, 0.0819614, -56.961, 2.718, 4.19477, -0.0646018, 0.0201671, 0.997665
		);
		TRI(
			9, 0, 2,
			7, 1, 0,
			9, 8, 0,
			13, 4, 6,
			7, 5, 1,
			8, 7, 0,
			11, 2, 3,
			10, 9, 2,
			13, 3, 4,
			11, 10, 2,
			12, 11, 3,
			13, 12, 3
		);
	};
	SubObject BorderStrip3_Shoulder
	{
		AlphaTest = 0.500000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		TangentSpace = true;
		PixelShader = Tex0NormalMap1;
		Texture = scnx.road.pavings.grass_area;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 1;
		Texture[1] = scnx.road.pavings.grass_area_nrm;
		TextureFilter[1] = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel[1] = 0;
		TextureMaxLevel[1] = 1000;
		TextureMaxLod[1] = 1000;
		TextureMinLod[1] = -1000;
		TextureAnisotropy[1] = 1;
		Storage = Buffer;
		TV(
			0.0469244, 0.856388, -28.3072, -2.35208, 6.03,
			0.0453377, 1.22017, -14.8473, -2.41078, -0.7,
			0, 0.856183, -28.3148, -4.08828, 6.03,
			-0.182099, 1.02349, -22.1246, -10.826, -0.7,
			0.0173531, 0.640518, -36.2944, -3.44621, 5.8171,
			-0.331527, 0.594955, -37.9802, -16.3548, -0.7,
			0.0584342, 0.414031, -44.6744, -1.92621, 5.24224,
			-0.256243, 0.349982, -47.0442, -13.5693, -0.7,
			0.106542, 0.201059, -52.5544, -0.146217, 4.56583,
			-0.170784, 0.136965, -54.9259, -10.4073, -0.7,
			0.154063, 0, -59.9936, 1.61204, 4.03,
			0.0529202, -0.155107, -65.7325, -2.13023, -0.7,
			0.198904, 0.00830007, -59.6865, 3.27115, 4.03,
			0.245439, -0.243105, -68.9884, 4.99296, -0.7 
		);
		STRIP(
			0, 			1, 			2, 			3, 			4, 			5, 			6, 			7,
			8, 			9, 			10, 			11, 			12, 			13  		);
	};
	SubObject BorderStrip4
	{
		AlphaTest = 0.200000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		Texture = area2.curbstone;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 3;
		Storage = Component;
		TVN(
			0, 0, 20.148, 3.42664, 6.01, -0.016467, -0.707067, 0.706954,
			0, 0.1, 20.1481, 3.44664, 6.03, -0.0164641, -0.706978, 0.707043,
			39.8859, 0, 59.6844, -3.31316, 4.01, -0.114164, -0.69825, 0.706692,
			39.8859, 0.1, 59.6885, -3.2936, 4.03, -0.114187, -0.698337, 0.706602,
			4.12132, 0, 24.3498, 3.28824, 5.96945, -0.0328355, -0.706479, 0.706877,
			4.12132, 0.1, 24.351, 3.3082, 5.98945, -0.0246432, -0.706684, 0.707005,
			8.24264, 0, 28.5271, 2.93267, 5.85663, -0.0550395, -0.70528, 0.706719,
			8.24264, 0.1, 28.5292, 2.95255, 5.87663, -0.0480099, -0.705579, 0.706933,
			12.364, 0, 32.6728, 2.39545, 5.68484, -0.0736631, -0.70377, 0.706551,
			12.364, 0.1, 32.6758, 2.41523, 5.70484, -0.0678235, -0.704114, 0.706793,
			16.4853, 0, 36.7848, 1.71225, 5.46733, -0.0887237, -0.702192, 0.706407,
			16.4853, 0.1, 36.7884, 1.73193, 5.48733, -0.0840583, -0.702541, 0.706631,
			20.6066, 0, 40.8647, 0.917854, 5.2174, -0.10033, -0.700735, 0.706314,
			20.6066, 0.1, 40.8687, 0.937442, 5.2374, -0.0968042, -0.701057, 0.706487,
			24.7279, 0, 44.9167, 0.0457116, 4.94831, -0.108614, -0.699535, 0.706288,
			24.7279, 0.1, 44.921, 0.0652329, 4.96831, -0.106191, -0.699805, 0.706388,
			28.8492, 0, 48.9468, -0.871936, 4.67335, -0.11368, -0.698689, 0.706333,
			28.8492, 0.1, 48.9513, -0.85245, 4.69335, -0.112334, -0.698888, 0.706352,
			32.9706, 0, 52.9619, -1.8037, 4.40578, -0.115578, -0.698267, 0.706446,
			32.9706, 0.1, 52.9664, -1.78421, 4.42578, -0.1153, -0.698373, 0.706386,
			37.0919, 0, 56.969, -2.71851, 4.15888, -0.114739, -0.698261, 0.706588,
			37.0919, 0.1, 56.9733, -2.69899, 4.17888, -0.115312, -0.698264, 0.706491
		);
		TRI(
			5, 0, 1,
			5, 4, 0,
			7, 4, 5,
			7, 6, 4,
			9, 6, 7,
			9, 8, 6,
			11, 8, 9,
			11, 10, 8,
			13, 10, 11,
			13, 12, 10,
			17, 14, 15,
			15, 12, 13,
			15, 14, 12,
			20, 3, 2,
			17, 16, 14,
			19, 16, 17,
			19, 18, 16,
			21, 18, 19,
			21, 20, 18,
			21, 3, 20
		);
	};
	SubObject BorderStrip4_Top
	{
		AlphaTest = 0.200000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		Texture = scnx.road.pavings.grass_area;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 1;
		Texture[1] = scnx.road.pavings.grass_area_nrm;
		TextureFilter[1] = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel[1] = 0;
		TextureMaxLevel[1] = 1000;
		TextureMaxLod[1] = 1000;
		TextureMinLod[1] = -1000;
		TextureAnisotropy[1] = 1;
		TangentSpace = true;
		PixelShader = Tex0NormalMap1;
		Storage = Component;
		TVN(
			0.211852, 0.3163, 31.8512, 4.54491, 5.75551, 0.0403416, 0.00790933, 0.998969,
			0.233375, 0.000223341, 20.1563, 5.34126, 6.03, 0.0176759, 0.0165307, 0.999537,
			0.169053, 0.569799, 41.2306, 2.96136, 5.2408, 0.0603354, -0.0090128, 0.998112,
			0.102612, 0.864129, 52.1209, 0.503028, 4.5113, 0.061064, -0.0155281, 0.998004,
			0.053072, 1.08, 60.1081, -1.32994, 4.03, 0.0540358, -0.0151515, 0.998415,
			0.182169, 0, 20.1481, 3.44664, 6.03, 0.0096474, -4.20783e-05, 0.999953,
			0, 1.06866, 59.6885, -3.2936, 4.03, 0.0523071, -0.0111765, 0.998569,
			0.178427, 0.113592, 24.351, 3.3082, 5.98945, 0.0212543, 0.016604, 0.99951,
			0.168815, 0.226518, 28.5292, 2.95255, 5.87663, 0.0343752, 0.00429723, 0.999304,
			0.154293, 0.338586, 32.6758, 2.41523, 5.70484, 0.0462824, -0.005849, 0.998891,
			0.135825, 0.449738, 36.7884, 1.73193, 5.48733, 0.055341, -0.00477954, 0.998437,
			0.114353, 0.560018, 40.8687, 0.937442, 5.2374, 0.061115, -0.0126065, 0.998048,
			0.0907793, 0.669539, 44.921, 0.0652329, 4.96831, 0.0639595, -0.0138942, 0.997854,
			0.0659771, 0.778465, 48.9513, -0.85245, 4.69335, 0.0638019, -0.0151764, 0.997846,
			0.0407943, 0.886981, 52.9664, -1.78421, 4.42578, 0.0605688, -0.0149285, 0.998048,
			0.0160705, 0.995278, 56.9733, -2.69899, 4.17888, 0.0553132, -0.0154118, 0.998342
		);
		TRI(
			10, 9, 0,
			10, 0, 2,
			15, 4, 6,
			7, 1, 0,
			7, 5, 1,
			8, 7, 0,
			9, 8, 0,
			12, 2, 3,
			11, 10, 2,
			12, 11, 2,
			15, 3, 4,
			13, 12, 3,
			14, 13, 3,
			15, 14, 3
		);
	};
	SubObject BorderStrip4_Shoulder
	{
		AlphaTest = 0.500000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		TangentSpace = true;
		PixelShader = Tex0NormalMap1;
		Texture = scnx.road.pavings.grass_area;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 1;
		Texture[1] = scnx.road.pavings.grass_area_nrm;
		TextureFilter[1] = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel[1] = 0;
		TextureMaxLevel[1] = 1000;
		TextureMaxLod[1] = 1000;
		TextureMinLod[1] = -1000;
		TextureAnisotropy[1] = 1;
		Storage = Buffer;
		TV(
			0.181898, -1.1788e-06, 20.148, 3.43664, 6.03,
			0.183485, -0.363782, 6.68816, 3.49534, -0.7,
			0.233375, 0.000223341, 20.1563, 5.34126, 6.03,
			0.41564, -0.16931, 13.8836, 12.0851, -0.7,
			0.211852, 0.3163, 31.8512, 4.54491, 5.75551,
			0.55796, 0.357199, 33.3644, 17.3509, -0.7,
			0.169053, 0.569799, 41.2306, 2.96136, 5.2408,
			0.483996, 0.631884, 43.5278, 14.6143, -0.7,
			0.102612, 0.864129, 52.1209, 0.503028, 4.5113,
			0.377278, 0.926647, 54.434, 10.6657, -0.7,
			0.053072, 1.08, 60.1081, -1.32994, 4.03,
			0.150959, 1.23361, 65.7917, 2.29188, -0.7,
			-0.000264304, 1.0686, 59.6865, -3.30338, 4.03,
			-0.0536886, 1.31864, 68.9376, -5.28008, -0.7 
		);
		STRIP(
			0, 			1, 			2, 			3, 			4, 			5, 			6, 			7,
			8, 			9, 			10, 			11, 			12, 			13  		);
	};
	SubObject BorderStrip5
	{
		AlphaTest = 0.200000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		Texture = area2.curbstone;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 3;
		Storage = Component;
		TVN(
			0, 0, 58.4348, -9.16116, 4.01, 0.19052, 0.681527, 0.706557,
			0, 0.1, 58.4306, -9.18071, 4.03, 0.19054, 0.681658, 0.706425,
			39.2689, 0, 20.1219, -2.55331, 6.01, 0.0182617, 0.706952, 0.707025,
			39.2689, 0.1, 20.1218, -2.57331, 6.03, 0.0182619, 0.70692, 0.707058,
			4.12132, 0, 54.3914, -8.26569, 4.23655, 0.198315, 0.679338, 0.706497,
			4.12132, 0.1, 54.387, -8.28519, 4.25655, 0.194424, 0.680474, 0.706485,
			8.24264, 0, 50.3685, -7.33512, 4.49464, 0.204772, 0.677591, 0.706353,
			8.24264, 0.1, 50.3639, -7.35459, 4.51464, 0.203497, 0.677949, 0.706379,
			12.364, 0, 46.3584, -6.4024, 4.77015, 0.203401, 0.678091, 0.70627,
			12.364, 0.1, 46.3539, -6.42189, 4.79015, 0.204719, 0.677627, 0.706335,
			16.4853, 0, 42.3538, -5.49994, 5.04895, 0.194165, 0.680783, 0.706258,
			16.4853, 0.1, 42.3495, -5.51948, 5.06895, 0.198106, 0.67954, 0.706361,
			20.6066, 0, 38.3481, -4.66016, 5.31691, 0.176894, 0.685366, 0.70632,
			20.6066, 0.1, 38.3442, -4.67978, 5.33691, 0.183532, 0.68348, 0.706453,
			24.7279, 0, 34.3362, -3.916, 5.55992, 0.15132, 0.69127, 0.706442,
			24.7279, 0.1, 34.3328, -3.93571, 5.57992, 0.160757, 0.688982, 0.706593,
			28.8492, 0, 30.3153, -3.30114, 5.76385, 0.117157, 0.697622, 0.706601,
			28.8492, 0.1, 30.3127, -3.32096, 5.78385, 0.129492, 0.695286, 0.70675,
			32.9706, 0, 26.2859, -2.84986, 5.91456, 0.0742206, 0.703215, 0.706758,
			32.9706, 0.1, 26.2841, -2.86978, 5.93456, 0.0895027, 0.701313, 0.706878,
			37.0919, 0, 22.2519, -2.59627, 5.99794, 0.0318179, 0.706297, 0.706939,
			37.0919, 0.1, 22.2512, -2.61625, 6.01794, 0.0453697, 0.705531, 0.706965
		);
		TRI(
			5, 4, 0,
			20, 3, 2,
			7, 4, 5,
			5, 0, 1,
			7, 6, 4,
			9, 6, 7,
			9, 8, 6,
			11, 8, 9,
			11, 10, 8,
			13, 10, 11,
			13, 12, 10,
			15, 12, 13,
			15, 14, 12,
			17, 14, 15,
			17, 16, 14,
			19, 16, 17,
			19, 18, 16,
			21, 18, 19,
			21, 20, 18,
			21, 3, 20
		);
	};
	SubObject BorderStrip5_Top
	{
		AlphaTest = 0.200000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		Texture = scnx.road.pavings.grass_area;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 1;
		Texture[1] = scnx.road.pavings.grass_area_nrm;
		TextureFilter[1] = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel[1] = 0;
		TextureMaxLevel[1] = 1000;
		TextureMaxLod[1] = 1000;
		TextureMinLod[1] = -1000;
		TextureAnisotropy[1] = 1;
		TangentSpace = true;
		PixelShader = Tex0NormalMap1;
		Storage = Component;
		TVN(
			0.0862503, 0.679785, 45.2656, -7.77622, 4.84178, 0.0639359, -0.0136378, 0.997826,
			0, 1.02528, 58.0489, -10.9675, 4.03, 0.0607849, -0.00162248, 0.998111,
			0.147872, 0.398703, 34.8656, -5.49621, 5.53506, 0.0534119, -0.0159703, 0.998402,
			0.173818, 0.177352, 26.6756, -4.53622, 5.91779, 0.0296588, -0.0103985, 0.99941,
			0.175765, 0, 20.1136, -4.46417, 6.03, 0.0113074, -0.00655513, 0.999877,
			0.0482909, 1.0356, 58.4306, -9.18071, 4.03, 0.0534141, -0.011413, 0.998507,
			0.22687, 0.000222898, 20.1218, -2.57331, 6.03, 0.00566274, -2.46987e-05, 0.999984,
			0.0724942, 0.926309, 54.387, -8.28519, 4.25655, 0.0592417, -0.00343018, 0.998189,
			0.0976455, 0.817577, 50.3639, -7.35459, 4.51464, 0.0647174, -0.00260465, 0.997865,
			0.122854, 0.709198, 46.3539, -6.42189, 4.79015, 0.0656414, -0.0147062, 0.997735,
			0.147243, 0.600971, 42.3495, -5.51948, 5.06895, 0.0643764, -0.0172502, 0.997773,
			0.169938, 0.492719, 38.3442, -4.67978, 5.33691, 0.0611345, -0.0164554, 0.997977,
			0.190048, 0.384303, 34.3328, -3.93571, 5.57992, 0.0538489, -0.010321, 0.998482,
			0.206663, 0.275651, 30.3127, -3.32096, 5.78385, 0.0433882, -0.0117568, 0.998942,
			0.218857, 0.166771, 26.2841, -2.86978, 5.93456, 0.0287885, -0.0032957, 0.999542,
			0.225709, 0.0577744, 22.2512, -2.61625, 6.01794, 0.0143176, -0.00613123, 0.999845
		);
		TRI(
			11, 0, 2,
			8, 1, 0,
			13, 2, 3,
			15, 3, 4,
			15, 4, 6,
			8, 7, 1,
			7, 5, 1,
			9, 8, 0,
			10, 9, 0,
			11, 10, 0,
			12, 11, 2,
			13, 12, 2,
			14, 13, 3,
			15, 14, 3
		);
	};
	SubObject BorderStrip5_Shoulder
	{
		AlphaTest = 0.500000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		TangentSpace = true;
		PixelShader = Tex0NormalMap1;
		Texture = scnx.road.pavings.grass_area;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 1;
		Texture[1] = scnx.road.pavings.grass_area_nrm;
		TextureFilter[1] = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel[1] = 0;
		TextureMaxLevel[1] = 1000;
		TextureMaxLod[1] = 1000;
		TextureMinLod[1] = -1000;
		TextureAnisotropy[1] = 1;
		Storage = Buffer;
		TV(
			0.0485552, 1.03565, 58.4327, -9.17093, 4.03,
			-0.00486908, 1.28568, 67.6839, -11.1476, -0.7,
			0, 1.02528, 58.0489, -10.9675, 4.03,
			-0.150743, 1.11933, 61.5288, -16.545, -0.7,
			0.0862503, 0.679785, 45.2656, -7.77622, 4.84178,
			-0.205371, 0.611433, 42.7366, -18.5662, -0.7,
			0.147872, 0.398703, 34.8656, -5.49621, 5.53506,
			-0.184103, 0.342998, 32.8045, -17.7793, -0.7,
			0.173818, 0.177352, 26.6756, -4.53622, 5.91779,
			-0.182674, 0.154566, 25.8325, -17.7264, -0.7,
			0.175765, 0, 20.1136, -4.46417, 6.03,
			-0.00532246, -0.183887, 13.3097, -11.1644, -0.7,
			0.22714, 0.000224077, 20.1219, -2.56331, 6.03,
			0.228726, -0.363556, 6.66199, -2.5046, -0.7 
		);
		STRIP(
			0, 			1, 			2, 			3, 			4, 			5, 			6, 			7,
			8, 			9, 			10, 			11, 			12, 			13  		);
	};
	SubObject BorderStrip6
	{
		AlphaTest = 0.200000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		Texture = area2.curbstone;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 3;
		Storage = Component;
		TVN(
			0, 0, -28.2812, 3.61787, 6.01, -0.00137925, -0.316225, 0.948683,
			0, 1, -28.2809, 3.67787, 6.03, -0.00137925, -0.316225, 0.948683,
			32.2863, 0, 20.1479, 3.40664, 6.01, -0.00137925, -0.316225, 0.948683,
			32.2863, 1, 20.1482, 3.46664, 6.03, -0.00137925, -0.316225, 0.948683
		);
		TRI(
			3, 0, 1,
			3, 2, 0
		);
	};
	SubObject BorderStrip6_Top
	{
		AlphaTest = 0.200000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		Texture = area2.pavement1;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 1;
		Texture[1] = area2.pavement1_nrm;
		TextureFilter[1] = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel[1] = 0;
		TextureMaxLevel[1] = 1000;
		TextureMaxLod[1] = 1000;
		TextureMinLod[1] = -1000;
		TextureAnisotropy[1] = 1;
		TangentSpace = true;
		PixelShader = Tex0NormalMap1;
		Storage = Component;
		TVN(
			0.0917038, 12.1089, 20.1546, 4.9339, 6.03, 0, 0, 1,
			0.109373, 0.00167784, -28.2742, 5.2166, 6.03, 0, 0, 1,
			0.0132018, 0, -28.2809, 3.67787, 6.03, 0, 0, 1,
			0, 12.1073, 20.1482, 3.46664, 6.03, 0, 0, 1
		);
		TRI(
			2, 1, 0,
			3, 2, 0
		);
	};
	SubObject BorderStrip6_Shoulder
	{
		AlphaTest = 0.500000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		TangentSpace = true;
		PixelShader = Tex0NormalMap1;
		Texture = area2.pavement1;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 1;
		Texture[1] = area2.pavement1_nrm;
		TextureFilter[1] = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel[1] = 0;
		TextureMaxLevel[1] = 1000;
		TextureMaxLod[1] = 1000;
		TextureMinLod[1] = -1000;
		TextureAnisotropy[1] = 1;
		Storage = Buffer;
		TV(
			0.0113268, -3.27118e-05, -28.281, 3.64787, 6.03,
			0.0113296, -0.00253269, -28.291, 3.64791, 5.33,
			0.109373, 0.00167784, -28.2742, 5.2166, 6.03,
			0.109687, 0.000435153, -28.2792, 5.22162, 5.33,
			0.0917038, 12.1089, 20.1546, 4.9339, 6.03,
			0.0920149, 12.1101, 20.1596, 4.93888, 5.33,
			-0.00187498, 12.1072, 20.148, 3.43664, 6.03,
			-0.00187771, 12.1097, 20.158, 3.43659, 5.33 
		);
		STRIP(
			0, 			1, 			2, 			3, 			4, 			5, 			6, 			7 
		);
	};
	SubObject BorderStrip7
	{
		AlphaTest = 0.200000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		Texture = area2.curbstone;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 3;
		Storage = Component;
		TVN(
			0, 0, 20.122, -2.53331, 6.01, 0.00137925, 0.316225, 0.948683,
			0, 1, 20.1217, -2.5933, 6.03, 0.00137925, 0.316225, 0.948683,
			32.2863, 0, -28.3071, -2.32208, 6.01, 0.00137925, 0.316225, 0.948683,
			32.2863, 1, -28.3073, -2.38208, 6.03, 0.00137925, 0.316225, 0.948683
		);
		TRI(
			3, 0, 1,
			3, 2, 0
		);
	};
	SubObject BorderStrip7_Top
	{
		AlphaTest = 0.200000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		Texture = area2.pavement1;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 1;
		Texture[1] = area2.pavement1_nrm;
		TextureFilter[1] = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel[1] = 0;
		TextureMaxLevel[1] = 1000;
		TextureMaxLod[1] = 1000;
		TextureMinLod[1] = -1000;
		TextureAnisotropy[1] = 1;
		TangentSpace = true;
		PixelShader = Tex0NormalMap1;
		Storage = Component;
		TVN(
			0.0126432, 0, -28.3138, -3.86675, 6.03, 0, 0, 1,
			0, 12.1073, 20.1153, -4.06904, 6.03, 0, 0, 1,
			0.0922334, 12.1089, 20.1217, -2.5933, 6.03, 0, 0, 1,
			0.105435, 0.00161889, -28.3073, -2.38208, 6.03, 0, 0, 1
		);
		TRI(
			3, 2, 1,
			3, 1, 0
		);
	};
	SubObject BorderStrip7_Shoulder
	{
		AlphaTest = 0.500000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		TangentSpace = true;
		PixelShader = Tex0NormalMap1;
		Texture = area2.pavement1;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 1;
		Texture[1] = area2.pavement1_nrm;
		TextureFilter[1] = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel[1] = 0;
		TextureMaxLevel[1] = 1000;
		TextureMaxLod[1] = 1000;
		TextureMinLod[1] = -1000;
		TextureAnisotropy[1] = 1;
		Storage = Buffer;
		TV(
			0.0941084, 12.1089, 20.1219, -2.56331, 6.03,
			0.0941057, 12.1114, 20.1319, -2.56335, 5.33,
			0, 12.1073, 20.1153, -4.06904, 6.03,
			-0.00031386, 12.1085, 20.1203, -4.07406, 5.33,
			0.0126432, 0, -28.3138, -3.86675, 6.03,
			0.0123321, -0.00125521, -28.3188, -3.87173, 5.33,
			0.10731, 0.00165161, -28.3072, -2.35208, 6.03,
			0.107313, -0.00084837, -28.3172, -2.35203, 5.33 
		);
		STRIP(
			0, 			1, 			2, 			3, 			4, 			5, 			6, 			7 
		);
	};
	SubObject Bridge0_Bottom
	{
		AlphaTest = 0.200000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		Texture = area2.pavement1;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 1;
		Texture[1] = area2.pavement1_nrm;
		TextureFilter[1] = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel[1] = 0;
		TextureMaxLevel[1] = 1000;
		TextureMaxLod[1] = 1000;
		TextureMinLod[1] = -1000;
		TextureAnisotropy[1] = 1;
		TangentSpace = true;
		PixelShader = Tex0NormalMap1;
		Storage = Component;
		TVN(
			0.482623, 0.0069492, -28.291, 3.64791, 5.33, -0, -0, -1,
			0.58098, 0.00991704, -28.2792, 5.22162, 5.33, -0, -0, -1,
			0.563309, 12.1196, 20.1596, 4.93888, 5.33, -0, -0, -1,
			0.469416, 12.1192, 20.158, 3.43659, 5.33, -0, -0, -1,
			0.0944196, 12.1127, 20.1319, -2.56335, 5.33, -0, -0, -1,
			0, 12.1098, 20.1203, -4.07406, 5.33, -0, -0, -1,
			0.0126459, 0, -28.3188, -3.87173, 5.33, -0, -0, -1,
			0.107627, 0.000406839, -28.3172, -2.35203, 5.33, -0, -0, -1
		);
		TRI(
			1, 0, 2,
			6, 5, 7,
			2, 0, 3,
			4, 3, 7,
			5, 4, 7,
			3, 0, 7
		);
	};
	SubObject BridgeFinish_4_5
	{
		AlphaTest = 0.500000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		TangentSpace = true;
		PixelShader = Tex0NormalMap1;
		Texture = scnx.road.pavings.grass_area;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 1;
		Texture[1] = scnx.road.pavings.grass_area_nrm;
		TextureFilter[1] = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel[1] = 0;
		TextureMaxLevel[1] = 1000;
		TextureMaxLod[1] = 1000;
		TextureMinLod[1] = -1000;
		TextureAnisotropy[1] = 1;
		Storage = Buffer;
		TV(
			0.098591, -0.764352, -28.281, 3.64787, 6.03,
			0.0970043, -0.400572, -14.8212, 3.58916, -0.7,
			0.097208, -0.757106, -28.0129, 3.5967, 5.89584,
			0.095653, -0.400578, -14.8214, 3.53916, -0.7,
			-0.0622499, -0.757801, -28.0387, -2.30325, 5.89584,
			-0.063805, -0.401273, -14.8471, -2.36078, -0.7,
			-0.0635696, -0.765059, -28.3072, -2.35208, 6.03,
			-0.0651563, -0.401279, -14.8473, -2.41078, -0.7 
		);
		STRIP(
			0, 			1, 			2, 			3, 			4, 			5, 			6, 			7 
		);
	};
	SubObject BridgeFinish_6_7
	{
		AlphaTest = 0.500000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		TangentSpace = true;
		PixelShader = Tex0NormalMap1;
		Texture = scnx.road.pavings.grass_area;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 1;
		Texture[1] = scnx.road.pavings.grass_area_nrm;
		TextureFilter[1] = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel[1] = 0;
		TextureMaxLevel[1] = 1000;
		TextureMaxLod[1] = 1000;
		TextureMinLod[1] = -1000;
		TextureAnisotropy[1] = 1;
		Storage = Buffer;
		TV(
			0.0944688, 0.180761, 6.68816, 3.49534, -0.7,
			0.0928821, 0.544541, 20.148, 3.43664, 6.03,
			0.0931174, 0.180755, 6.68794, 3.44535, -0.7,
			0.0915624, 0.537284, 19.8795, 3.38781, 5.89584,
			-0.0663405, 0.18006, 6.66221, -2.4546, -0.7,
			-0.0678955, 0.536588, 19.8538, -2.51214, 5.89584,
			-0.0676918, 0.180054, 6.66199, -2.5046, -0.7,
			-0.0692785, 0.543834, 20.1219, -2.56331, 6.03 
		);
		STRIP(
			0, 			1, 			2, 			3, 			4, 			5, 			6, 			7 
		);
	};
	SubObject RoadSurface_0
	{
		AlphaTest = 0.500000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		TangentSpace = true;
		PixelShader = Tex0NormalMap1;
		Texture = SCNX.ROAD.PAVINGS.tar_new2;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 3;
		Texture[1] = SCNX.ROAD.PAVINGS.tar_new2_nrm;
		TextureFilter[1] = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel[1] = 0;
		TextureMaxLevel[1] = 1000;
		TextureMaxLod[1] = 1000;
		TextureMinLod[1] = -1000;
		TextureAnisotropy[1] = 3;
		Storage = Buffer;
		TVN(
			0, 0.0976563, 4.29424, 5.33438, 0, 0, 0, 1,
			1, 0.0976563, 6.82421, 5.32214, 0, 0, 0, 1,
			1, 0, 6.77695, -4.44338, 0, 0, 0, 1,
			0, 0, 4.24698, -4.43113, 0, 0, 0, 1,
			0, 0.0976563, 0.544283, 5.35253, 0, 0, 0, 1,
			1, 0.0976563, 4.29424, 5.33438, 0, 0, 0, 1,
			1, 0, 4.24698, -4.43113, 0, 0, 0, 1,
			0, 0, 0.497027, -4.41299, 0, 0, 0, 1,
			0, 0.0976563, -3.20567, 5.37067, 0, 0, 0, 1,
			1, 0.0976563, 0.544283, 5.35253, 0, 0, 0, 1,
			1, 0, 0.497027, -4.41299, 0, 0, 0, 1,
			0, 0, -3.25293, -4.39484, 0, 0, 0, 1,
			1, 0.0976563, -9.95559, 5.40334, 0, 0, 0, 1,
			0, 0.0976563, -6.20564, 5.38519, 0, 0, 0, 1,
			0, 0, -6.25289, -4.38032, 0, 0, 0, 1,
			1, 0, -10.0029, -4.36218, 0, 0, 0, 1,
			1, 0.0976563, -13.7056, 5.42148, 0, 0, 0, 1,
			0, 0.0976563, -9.95559, 5.40334, 0, 0, 0, 1,
			0, 0, -10.0029, -4.36218, 0, 0, 0, 1,
			1, 0, -13.7528, -4.34403, 0, 0, 0, 1,
			1, 0.0976563, -16.2355, 5.43373, 0, 0, 0, 1,
			0, 0.0976563, -13.7056, 5.42148, 0, 0, 0, 1,
			0, 0, -13.7528, -4.34403, 0, 0, 0, 1,
			1, 0, -16.2828, -4.33179, 0, 0, 0, 1 
		);
		TRI(
			  0,  1,  2,
			  2,  3,  0,
			  4,  5,  6,
			  6,  7,  4,
			  8,  9, 10,
			 10, 11,  8,
			 12, 13, 14,
			 14, 15, 12,
			 16, 17, 18,
			 18, 19, 16,
			 20, 21, 22,
			 22, 23, 20 
		);
	};
	SubObject RoadSurface_1
	{
		AlphaTest = 0.500000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		TangentSpace = true;
		PixelShader = Tex0NormalMap1;
		Texture = SCNX.ROAD.PAVINGS.tar2;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 3;
		Texture[1] = SCNX.ROAD.PAVINGS.tar2_nrm;
		TextureFilter[1] = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel[1] = 0;
		TextureMaxLevel[1] = 1000;
		TextureMaxLod[1] = 1000;
		TextureMinLod[1] = -1000;
		TextureAnisotropy[1] = 3;
		Storage = Component;
		TV(
			0, 8.83154, -28.2941, 0.647895, 6,
			1, 8.83154, -28.2809, 3.67787, 6,
			1, 8.83154, -28.2809, 3.67787, 6,
			0, 8.33154, -23.2942, 0.626087, 6,
			0, 8.83154, -28.2941, 0.647895, 6,
			0, 8.33154, -23.2942, 0.626087, 6,
			0, 7.83154, -18.2942, 0.60428, 6,
			0, 7.83154, -18.2942, 0.60428, 6,
			0, 7.33154, -13.2943, 0.582472, 6,
			0, 7.33154, -13.2943, 0.582472, 6,
			0, 6.83154, -8.2943, 0.560664, 6,
			1, 6.33154, 20.1482, 3.46664, 6,
			0, 6.33154, -3.29435, 0.538856, 6,
			0, 6.33154, -3.29435, 0.538856, 6,
			1, 6.33154, 20.1482, 3.46664, 6,
			0, 5.83154, 1.70561, 0.517048, 6,
			0, 5.83154, 1.70561, 0.517048, 6,
			0, 5.33154, 6.70556, 0.49524, 6,
			0, 5.33154, 6.70556, 0.49524, 6,
			0, 4.83154, 11.7055, 0.473432, 6,
			0, 4.83154, 11.7055, 0.473432, 6,
			0, 4.33154, 16.7055, 0.451624, 6,
			0, 4.33154, 16.7055, 0.451624, 6,
			0, 3.98859, 20.1349, 0.436666, 6,
			0, 3.98859, 20.1349, 0.436666, 6,
			1, 3.98859, 20.1482, 3.46664, 6,
			1, 3.57646, 24.3522, 3.32817, 5.95945,
			1, 3.57646, 24.3522, 3.32817, 5.95945,
			0, 3.57646, 24.1697, 0.303664, 5.95945,
			0, 3.98859, 20.1349, 0.436666, 6,
			0, 3.57646, 24.1697, 0.303664, 5.95945,
			1, 3.57646, 24.3522, 3.32817, 5.95945,
			1, 3.16433, 28.5314, 2.97243, 5.84663,
			1, 3.16433, 28.5314, 2.97243, 5.84663,
			0, 3.16433, 28.204, -0.0398271, 5.84663,
			0, 3.57646, 24.1697, 0.303664, 5.95945,
			0, 3.16433, 28.204, -0.0398271, 5.84663,
			1, 3.16433, 28.5314, 2.97243, 5.84663,
			1, 2.7522, 32.6787, 2.43501, 5.67484,
			1, 2.7522, 32.6787, 2.43501, 5.67484,
			0, 2.7522, 32.2315, -0.561812, 5.67484,
			0, 3.16433, 28.204, -0.0398271, 5.84663,
			0, 2.7522, 32.2315, -0.561812, 5.67484,
			1, 2.7522, 32.6787, 2.43501, 5.67484,
			1, 2.34006, 36.792, 1.75161, 5.45733,
			1, 2.34006, 36.792, 1.75161, 5.45733,
			0, 2.34006, 36.25, -1.22954, 5.45733,
			0, 2.7522, 32.2315, -0.561812, 5.67484,
			0, 2.34006, 36.25, -1.22954, 5.45733,
			1, 2.34006, 36.792, 1.75161, 5.45733,
			1, 1.92793, 40.8728, 0.957029, 5.2074,
			1, 1.92793, 40.8728, 0.957029, 5.2074,
			0, 1.92793, 40.2605, -2.01046, 5.2074,
			0, 2.34006, 36.25, -1.22954, 5.45733,
			0, 1.92793, 40.2605, -2.01046, 5.2074,
			1, 1.92793, 40.8728, 0.957029, 5.2074,
			1, 1.5158, 44.9254, 0.0847542, 4.93831,
			1, 1.5158, 44.9254, 0.0847542, 4.93831,
			0, 1.5158, 44.2664, -2.87272, 4.93831,
			0, 1.92793, 40.2605, -2.01046, 5.2074,
			0, 1.5158, 44.2664, -2.87272, 4.93831,
			1, 1.5158, 44.9254, 0.0847542, 4.93831,
			1, 1.10367, 48.9558, -0.832964, 4.66335,
			1, 1.10367, 48.9558, -0.832964, 4.66335,
			0, 1.10367, 48.2732, -3.78507, 4.66335,
			0, 1.5158, 44.2664, -2.87272, 4.93831,
			0, 1.10367, 48.2732, -3.78507, 4.66335,
			1, 1.10367, 48.9558, -0.832964, 4.66335,
			1, 0.691536, 52.9709, -1.76473, 4.39578,
			0, 0.691536, 52.2874, -4.71663, 4.39578,
			0, 0.691536, 52.2874, -4.71663, 4.39578,
			1, 0.691536, 52.9709, -1.76473, 4.39578,
			1, 0.279404, 56.9777, -2.67948, 4.14888,
			1, 0.279404, 56.9777, -2.67948, 4.14888,
			0, 0.279404, 56.3163, -5.63641, 4.14888,
			0, 0.691536, 52.2874, -4.71663, 4.39578,
			0, 0.279404, 56.3163, -5.63641, 4.14888,
			1, 0.279404, 56.9777, -2.67948, 4.14888,
			1, -2.77556e-16, 59.6927, -3.27404, 4,
			1, -2.77556e-16, 59.6927, -3.27404, 4,
			0, -2.77556e-16, 59.0596, -6.23716, 4,
			0, 0.279404, 56.3163, -5.63641, 4.14888,
			0, 11.9725, -59.1404, 6.22104, 4,
			1, 11.9725, -58.5889, 9.20043, 4,
			1, 11.5604, -54.4493, 8.35405, 4.2498,
			1, 11.5604, -54.4493, 8.35405, 4.2498,
			0, 11.5604, -55.1029, 5.39539, 4.2498,
			0, 11.9725, -59.1404, 6.22104, 4,
			0, 11.5604, -55.1029, 5.39539, 4.2498,
			1, 11.5604, -54.4493, 8.35405, 4.2498,
			1, 11.1482, -50.3842, 7.4139, 4.56512,
			1, 11.1482, -50.3842, 7.4139, 4.56512,
			0, 11.1482, -51.0876, 4.46668, 4.56512,
			0, 11.5604, -55.1029, 5.39539, 4.2498,
			0, 11.1482, -51.0876, 4.46668, 4.56512,
			1, 11.1482, -50.3842, 7.4139, 4.56512,
			1, 10.7361, -46.3776, 6.4523, 4.91302,
			0, 10.7361, -47.0801, 3.50485, 4.91302,
			0, 10.7361, -47.0801, 3.50485, 4.91302,
			1, 10.7361, -46.3776, 6.4523, 4.91302,
			1, 10.324, -42.4134, 5.538, 5.26057,
			1, 10.324, -42.4134, 5.538, 5.26057,
			0, 10.324, -43.0642, 2.57871, 5.26057,
			0, 10.7361, -47.0801, 3.50485, 4.91302,
			0, 10.324, -43.0642, 2.57871, 5.26057,
			1, 10.324, -42.4134, 5.538, 5.26057,
			1, 9.91185, -38.4788, 4.73845, 5.57486,
			1, 9.91185, -38.4788, 4.73845, 5.57486,
			0, 9.91185, -39.0256, 1.75819, 5.57486,
			0, 10.324, -43.0642, 2.57871, 5.26057,
			0, 9.91185, -39.0256, 1.75819, 5.57486,
			1, 9.91185, -38.4788, 4.73845, 5.57486,
			1, 9.49972, -34.5671, 4.12121, 5.82294,
			1, 9.49972, -34.5671, 4.12121, 5.82294,
			0, 9.49972, -34.9551, 1.11615, 5.82294,
			0, 9.91185, -39.0256, 1.75819, 5.57486,
			0, 9.49972, -34.9551, 1.11615, 5.82294,
			1, 9.49972, -34.5671, 4.12121, 5.82294,
			1, 9.08759, -30.6796, 3.75314, 5.97188,
			1, 9.08759, -30.6796, 3.75314, 5.97188,
			0, 9.08759, -30.853, 0.728108, 5.97188,
			0, 9.49972, -34.9551, 1.11615, 5.82294,
			0, 9.08759, -30.853, 0.728108, 5.97188,
			1, 9.08759, -30.6796, 3.75314, 5.97188,
			1, 8.83154, -28.2809, 3.67787, 6,
			1, 8.83154, -28.2809, 3.67787, 6,
			0, 8.83154, -28.2941, 0.647895, 6,
			0, 9.08759, -30.853, 0.728108, 5.97188,
			1, 8.83154, -28.3073, -2.38208, 6,
			1, 8.83154, -28.3073, -2.38208, 6,
			0, 6.83154, -8.2943, 0.560664, 6,
			1, 6.33154, 20.1217, -2.5933, 6,
			1, 6.33154, 20.1217, -2.5933, 6,
			0, 3.98859, 20.1349, 0.436666, 6,
			1, 11.9725, -59.6919, 3.24165, 4,
			0, 11.9725, -59.1404, 6.22104, 4,
			0, 11.5604, -55.1029, 5.39539, 4.2498,
			0, 11.5604, -55.1029, 5.39539, 4.2498,
			1, 11.5604, -56.9651, 2.69844, 4.16477,
			1, 11.9725, -59.6919, 3.24165, 4,
			1, 11.5604, -56.9651, 2.69844, 4.16477,
			0, 11.5604, -55.1029, 5.39539, 4.2498,
			0, 11.1482, -51.0876, 4.46668, 4.56512,
			0, 11.1482, -51.0876, 4.46668, 4.56512,
			1, 11.1482, -53.0099, 1.8084, 4.46352,
			1, 11.5604, -56.9651, 2.69844, 4.16477,
			1, 11.1482, -53.0099, 1.8084, 4.46352,
			0, 11.1482, -51.0876, 4.46668, 4.56512,
			0, 10.7361, -47.0801, 3.50485, 4.91302,
			0, 10.7361, -47.0801, 3.50485, 4.91302,
			1, 10.7361, -49.0162, 0.852857, 4.80493,
			1, 11.1482, -53.0099, 1.8084, 4.46352,
			1, 10.7361, -49.0162, 0.852857, 4.80493,
			0, 10.7361, -47.0801, 3.50485, 4.91302,
			0, 10.324, -43.0642, 2.57871, 5.26057,
			1, 10.324, -44.9686, -0.0999804, 5.15609,
			1, 10.324, -44.9686, -0.0999804, 5.15609,
			0, 9.91185, -39.0256, 1.75819, 5.57486,
			1, 9.91185, -40.8505, -0.979051, 5.48407,
			1, 10.324, -44.9686, -0.0999804, 5.15609,
			1, 9.91185, -40.8505, -0.979051, 5.48407,
			0, 9.91185, -39.0256, 1.75819, 5.57486,
			0, 9.49972, -34.9551, 1.11615, 5.82294,
			0, 9.49972, -34.9551, 1.11615, 5.82294,
			1, 9.49972, -36.6485, -1.70809, 5.75593,
			1, 9.91185, -40.8505, -0.979051, 5.48407,
			1, 9.49972, -36.6485, -1.70809, 5.75593,
			0, 9.49972, -34.9551, 1.11615, 5.82294,
			0, 9.08759, -30.853, 0.728108, 5.97188,
			0, 9.08759, -30.853, 0.728108, 5.97188,
			1, 9.08759, -32.3577, -2.20461, 5.93875,
			1, 9.49972, -36.6485, -1.70809, 5.75593,
			1, 9.08759, -32.3577, -2.20461, 5.93875,
			0, 9.08759, -30.853, 0.728108, 5.97188,
			0, 8.83154, -28.2941, 0.647895, 6,
			0, 8.83154, -28.2941, 0.647895, 6,
			1, 8.83154, -28.3073, -2.38208, 6,
			1, 9.08759, -32.3577, -2.20461, 5.93875,
			1, 3.98859, 20.1217, -2.5933, 6,
			0, 3.5931, 24.1697, 0.303664, 5.95945,
			0, 3.5931, 24.1697, 0.303664, 5.95945,
			1, 3.5931, 22.2505, -2.63624, 5.98794,
			1, 3.98859, 20.1217, -2.5933, 6,
			1, 3.5931, 22.2505, -2.63624, 5.98794,
			0, 3.5931, 24.1697, 0.303664, 5.95945,
			0, 3.19532, 28.204, -0.0398271, 5.84663,
			0, 3.19532, 28.204, -0.0398271, 5.84663,
			1, 3.19532, 26.2823, -2.8897, 5.90456,
			1, 3.5931, 22.2505, -2.63624, 5.98794,
			1, 3.19532, 26.2823, -2.8897, 5.90456,
			0, 3.19532, 28.204, -0.0398271, 5.84663,
			0, 2.79515, 32.2315, -0.561812, 5.67484,
			0, 2.79515, 32.2315, -0.561812, 5.67484,
			1, 2.79515, 30.31, -3.34079, 5.75385,
			1, 3.19532, 26.2823, -2.8897, 5.90456,
			1, 2.79515, 30.31, -3.34079, 5.75385,
			0, 2.79515, 32.2315, -0.561812, 5.67484,
			0, 2.39255, 36.25, -1.22954, 5.45733,
			0, 2.39255, 36.25, -1.22954, 5.45733,
			1, 2.39255, 34.3294, -3.95543, 5.54992,
			1, 2.79515, 30.31, -3.34079, 5.75385,
			1, 2.39255, 34.3294, -3.95543, 5.54992,
			0, 2.39255, 36.25, -1.22954, 5.45733,
			0, 1.98756, 40.2605, -2.01046, 5.2074,
			0, 1.98756, 40.2605, -2.01046, 5.2074,
			1, 1.98756, 38.3403, -4.69939, 5.30691,
			1, 2.39255, 34.3294, -3.95543, 5.54992,
			1, 1.98756, 38.3403, -4.69939, 5.30691,
			0, 1.98756, 40.2605, -2.01046, 5.2074,
			0, 1.58021, 44.2664, -2.87272, 4.93831,
			1, 1.58021, 42.3452, -5.53902, 5.03895,
			1, 1.58021, 42.3452, -5.53902, 5.03895,
			0, 1.58021, 44.2664, -2.87272, 4.93831,
			0, 1.17053, 48.2732, -3.78507, 4.66335,
			0, 1.17053, 48.2732, -3.78507, 4.66335,
			1, 1.17053, 46.3494, -6.44138, 4.76015,
			1, 1.58021, 42.3452, -5.53902, 5.03895,
			1, 1.17053, 46.3494, -6.44138, 4.76015,
			0, 1.17053, 48.2732, -3.78507, 4.66335,
			0, 0.758488, 52.2874, -4.71663, 4.39578,
			0, 0.758488, 52.2874, -4.71663, 4.39578,
			1, 0.758488, 50.3594, -7.37407, 4.48464,
			1, 1.17053, 46.3494, -6.44138, 4.76015,
			1, 0.758488, 50.3594, -7.37407, 4.48464,
			0, 0.758488, 52.2874, -4.71663, 4.39578,
			0, 0.344056, 56.3163, -5.63641, 4.14888,
			0, 0.344056, 56.3163, -5.63641, 4.14888,
			1, 0.344056, 54.3825, -8.30469, 4.22655,
			1, 0.758488, 50.3594, -7.37407, 4.48464,
			1, 0.344056, 54.3825, -8.30469, 4.22655,
			0, 0.344056, 56.3163, -5.63641, 4.14888,
			0, 0.0616986, 59.0596, -6.23716, 4,
			0, 0.0616986, 59.0596, -6.23716, 4,
			1, 0.0616986, 58.4265, -9.20027, 4,
			1, 0.344056, 54.3825, -8.30469, 4.22655 
		);
		TRI(
			  0,  1,  1,
			  2,  3,  4,
			  5,  1,  1,
			  2,  6,  3,
			  7,  1,  1,
			  2,  8,  6,
			  9,  1,  1,
			  2, 10,  8,
			 10,  2, 11,
			 11, 12, 10,
			 13, 14, 14,
			 11, 15, 12,
			 16, 14, 14,
			 11, 17, 15,
			 18, 14, 14,
			 11, 19, 17,
			 20, 14, 14,
			 11, 21, 19,
			 22, 14, 14,
			 11, 23, 21,
			 24, 25, 26,
			 27, 28, 29,
			 30, 31, 32,
			 33, 34, 35,
			 36, 37, 38,
			 39, 40, 41,
			 42, 43, 44,
			 45, 46, 47,
			 48, 49, 50,
			 51, 52, 53,
			 54, 55, 56,
			 57, 58, 59,
			 60, 61, 62,
			 63, 64, 65,
			 66, 67, 68,
			 68, 69, 66,
			 70, 71, 72,
			 73, 74, 75,
			 76, 77, 78,
			 79, 80, 81,
			 82, 83, 84,
			 85, 86, 87,
			 88, 89, 90,
			 91, 92, 93,
			 94, 95, 96,
			 96, 97, 94,
			 98, 99,100,
			101,102,103,
			104,105,106,
			107,108,109,
			110,111,112,
			113,114,115,
			116,117,118,
			119,120,121,
			122,123,124,
			125,126,127,
			128,  4,  3,
			  5,129,129,
			128,  3,  6,
			  7,129,129,
			128,  6,  8,
			  9,129,129,
			128,  8, 10,
			130,129,129,
			128, 10, 12,
			 12,131,128,
			131, 12, 15,
			 16,132,132,
			131, 15, 17,
			 18,132,132,
			131, 17, 19,
			 20,132,132,
			131, 19, 21,
			 22,132,132,
			131, 21, 23,
			133,132,132,
			134,135,136,
			137,138,139,
			140,141,142,
			143,144,145,
			146,147,148,
			149,150,151,
			152,153,154,
			154,155,152,
			156,109,108,
			157,158,159,
			160,161,162,
			163,164,165,
			166,167,168,
			169,170,171,
			172,173,174,
			175,176,177,
			178, 24,179,
			180,181,182,
			183,184,185,
			186,187,188,
			189,190,191,
			192,193,194,
			195,196,197,
			198,199,200,
			201,202,203,
			204,205,206,
			207,208,209,
			209,210,207,
			211,212,213,
			214,215,216,
			217,218,219,
			220,221,222,
			223,224,225,
			226,227,228,
			229,230,231,
			232,233,234 
		);
	};
	SubObject BasePlate
	{
		AlphaTest = 0.500000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		TangentSpace = true;
		PixelShader = Tex0NormalMap1;
		Texture = SCNX.ROAD.PAVINGS.tar2;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 3;
		Texture[1] = SCNX.ROAD.PAVINGS.tar2_nrm;
		TextureFilter[1] = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel[1] = 0;
		TextureMaxLevel[1] = 1000;
		TextureMaxLod[1] = 1000;
		TextureMinLod[1] = -1000;
		TextureAnisotropy[1] = 3;
		Storage = Buffer;
		TVN(
			0.976551, 0.304722, -3.20567, 5.37067, 0, 0, 0, 1,
			0.978003, 0.00472558, -6.20564, 5.38519, 0, 0, 0, 1,
			0, 0.299996, -3.25293, -4.39484, 0, 0, 0, 1,
			0.0014517, 0, -6.25289, -4.38032, 0, 0, 0, 1 
		);
		TRI(
			  3,  0,  2,
			  3,  1,  0 
		);
	};
	SubObject ChanIslandSep0
	{
		AlphaTest = 0.200000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		Texture = area2.curbstone;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 3;
		Storage = Component;
		TVN(
			9.70168, 0, -6.28289, -4.38018, 0.01, -0.316147, -0.0234819, 0.948089,
			9.70168, 1, -6.22289, -4.38047, 0.03, -0.316147, -0.0234819, 0.948089,
			0.00666667, 0, -6.28285, -4.37018, 0.01, -0.316224, 0.00153022, 0.948683,
			0.00666667, 1, -6.22285, -4.37047, 0.03, -0.316224, 0.00153022, 0.948683,
			6.50375, 0, -6.23569, 5.37534, 0.01, -0.316224, 0.00153022, 0.948683,
			6.50375, 1, -6.17569, 5.37505, 0.03, -0.316224, 0.00153022, 0.948683,
			0, 0, -6.23564, 5.38534, 0.01, -0.315799, 0.0348771, 0.947892,
			0, 1, -6.17564, 5.38505, 0.03, -0.316011, 0.0182037, 0.948287,
			3.19126, 0, -3.17567, 5.37053, 0.01, 0.316173, 0.0151445, 0.948287,
			3.19126, 1, -3.23567, 5.37082, 0.03, 0.316122, 0.0318192, 0.947892,
			0.00666667, 0, -3.17572, 5.36053, 0.01, 0.316224, -0.00153022, 0.948683,
			0.00666667, 1, -3.23572, 5.36082, 0.03, 0.316224, -0.00153022, 0.948683,
			6.50375, 0, -3.22288, -4.38499, 0.01, 0.316224, -0.00153022, 0.948683,
			6.50375, 1, -3.28288, -4.3847, 0.03, 0.316224, -0.00153022, 0.948683,
			6.51042, 0, -3.22293, -4.39499, 0.01, 0.315905, -0.0265404, 0.948089,
			6.51042, 1, -3.28293, -4.3947, 0.03, 0.315905, -0.0265404, 0.948089,
			6.82955, 0, -3.3001, -4.86741, 0.01, 0.305127, -0.0832167, 0.947496,
			6.82955, 1, -3.35707, -4.8486, 0.03, 0.294669, -0.114883, 0.947496,
			7.14867, 0, -3.51948, -5.29287, 0.01, 0.254612, -0.186876, 0.947496,
			7.14867, 1, -3.56785, -5.25737, 0.03, 0.254612, -0.186876, 0.947496,
			7.4678, 0, -3.8596, -5.62972, 0.01, 0.170866, -0.266144, 0.947496,
			7.4678, 1, -3.89463, -5.581, 0.03, 0.19794, -0.246673, 0.947496,
			7.78692, 0, -4.28716, -5.84497, 0.01, 0.0802598, -0.305919, 0.947496,
			7.78692, 1, -4.30543, -5.78782, 0.03, 0.112026, -0.295767, 0.947496,
			8.10605, 0, -4.76032, -5.91756, 0.01, -0.00152831, -0.315828, 0.947496,
			8.10605, 1, -4.76002, -5.85756, 0.03, -0.00152831, -0.315828, 0.947496,
			8.42518, 0, -5.23274, -5.84039, 0.01, -0.0832167, -0.305127, 0.947496,
			8.42518, 1, -5.21393, -5.78342, 0.03, -0.114883, -0.294669, 0.947496,
			8.7443, 0, -5.6582, -5.62101, 0.01, -0.173433, -0.264478, 0.947496,
			8.7443, 1, -5.6227, -5.57264, 0.03, -0.200318, -0.244746, 0.947496,
			9.06343, 0, -5.99504, -5.28089, 0.01, -0.256409, -0.184403, 0.947496,
			9.06343, 1, -5.94633, -5.24586, 0.03, -0.256409, -0.184403, 0.947496,
			9.38256, 0, -6.2103, -4.85333, 0.01, -0.300843, -0.0961428, 0.947496,
			9.38256, 1, -6.15315, -4.83507, 0.03, -0.300843, -0.0961428, 0.947496,
			0.319126, 0, -6.15847, 5.85776, 0.01, -0.299898, 0.0990498, 0.947496,
			0.319126, 1, -6.10149, 5.83895, 0.03, -0.299898, 0.0990498, 0.947496,
			0.638253, 0, -5.93909, 6.28322, 0.01, -0.264478, 0.173433, 0.947496,
			0.638253, 1, -5.89072, 6.24772, 0.03, -0.244746, 0.200318, 0.947496,
			0.957379, 0, -5.59897, 6.62007, 0.01, -0.184403, 0.256409, 0.947496,
			0.957379, 1, -5.56394, 6.57135, 0.03, -0.184403, 0.256409, 0.947496,
			1.27651, 0, -5.17141, 6.83532, 0.01, -0.0802598, 0.305919, 0.947496,
			1.27651, 1, -5.15314, 6.77817, 0.03, -0.112026, 0.295767, 0.947496,
			1.59563, 0, -4.69825, 6.90791, 0.01, 0.00152831, 0.315828, 0.947496,
			1.59563, 1, -4.69854, 6.84791, 0.03, 0.00152831, 0.315828, 0.947496,
			1.91476, 0, -4.22582, 6.83074, 0.01, 0.0832167, 0.305127, 0.947496,
			1.91476, 1, -4.24464, 6.77377, 0.03, 0.114883, 0.294669, 0.947496,
			2.23388, 0, -3.80037, 6.61136, 0.01, 0.186876, 0.254612, 0.947496,
			2.23388, 1, -3.83587, 6.56299, 0.03, 0.186876, 0.254612, 0.947496,
			2.55301, 0, -3.46352, 6.27124, 0.01, 0.266144, 0.170866, 0.947496,
			2.55301, 1, -3.51223, 6.23621, 0.03, 0.246673, 0.19794, 0.947496,
			2.87214, 0, -3.24827, 5.84368, 0.01, 0.305919, 0.0802598, 0.947496,
			2.87214, 1, -3.30542, 5.82542, 0.03, 0.295767, 0.112026, 0.947496
		);
		TRI(
			3, 0, 2,
			21, 18, 20,
			12, 11, 10,
			15, 13, 12,
			4, 3, 2,
			5, 3, 4,
			3, 1, 0,
			7, 4, 6,
			11, 8, 10,
			7, 5, 4,
			36, 35, 34,
			38, 37, 36,
			13, 11, 12,
			11, 9, 8,
			15, 12, 14,
			16, 15, 14,
			18, 17, 16,
			23, 20, 22,
			17, 15, 16,
			19, 17, 18,
			25, 22, 24,
			21, 19, 18,
			26, 25, 24,
			23, 21, 20,
			28, 27, 26,
			25, 23, 22,
			30, 29, 28,
			27, 25, 26,
			33, 30, 32,
			29, 27, 28,
			33, 32, 0,
			31, 29, 30,
			33, 0, 1,
			33, 31, 30,
			35, 6, 34,
			35, 7, 6,
			41, 38, 40,
			37, 35, 36,
			43, 40, 42,
			39, 37, 38,
			44, 43, 42,
			41, 39, 38,
			46, 45, 44,
			43, 41, 40,
			49, 46, 48,
			45, 43, 44,
			51, 48, 50,
			47, 45, 46,
			51, 50, 9,
			49, 47, 46,
			50, 8, 9,
			51, 49, 48
		);
	};
	SubObject ChanIslandSep0_Top
	{
		AlphaTest = 0.200000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		Texture = area2.pavement1;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 1;
		Texture[1] = area2.pavement1_nrm;
		TextureFilter[1] = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | RepeatT;
		TextureBaseLevel[1] = 0;
		TextureMaxLevel[1] = 1000;
		TextureMaxLod[1] = 1000;
		TextureMinLod[1] = -1000;
		TextureAnisotropy[1] = 1;
		TangentSpace = true;
		PixelShader = Tex0NormalMap1;
		Storage = Component;
		TVN(
			0.155709, 0.103114, -6.22289, -4.38047, 0.03, 0, 0, 1,
			0.156151, 0.104881, -6.22285, -4.37047, 0.03, 0, 0, 1,
			0.586851, 1.82768, -6.17569, 5.37505, 0.03, 0, 0, 1,
			0.587293, 1.82945, -6.17564, 5.38505, 0.03, 0, 0, 1,
			0.457362, 2.34917, -3.23567, 5.37082, 0.03, 0, 0, 1,
			0.45692, 2.3474, -3.23572, 5.36082, 0.03, 0, 0, 1,
			0.0262204, 0.624605, -3.28288, -4.3847, 0.03, 0, 0, 1,
			0.0257784, 0.622837, -3.28293, -4.3947, 0.03, 0, 0, 1,
			0.00888264, 0.529817, -3.35707, -4.8486, 0.03, 0, 0, 1,
			0, 0.420465, -3.56785, -5.25737, 0.03, 0, 0, 1,
			0, 0.305486, -3.89463, -5.581, 0.03, 0, 0, 1,
			0.00888264, 0.196134, -4.30543, -5.78782, 0.03, 0, 0, 1,
			0.0257784, 0.103114, -4.76002, -5.85756, 0.03, 0, 0, 1,
			0.0490335, 0.0355306, -5.21393, -5.78342, 0.03, 0, 0, 1,
			0.0763714, 0, -5.6227, -5.57264, 0.03, 0, 0, 1,
			0.105116, 0, -5.94633, -5.24586, 0.03, 0, 0, 1,
			0.132454, 0.0355306, -6.15315, -4.83507, 0.03, 0, 0, 1,
			0.604189, 1.92247, -6.10149, 5.83895, 0.03, 0, 0, 1,
			0.613072, 2.03182, -5.89072, 6.24772, 0.03, 0, 0, 1,
			0.613072, 2.1468, -5.56394, 6.57135, 0.03, 0, 0, 1,
			0.604189, 2.25615, -5.15314, 6.77817, 0.03, 0, 0, 1,
			0.587293, 2.34917, -4.69854, 6.84791, 0.03, 0, 0, 1,
			0.564038, 2.41676, -4.24464, 6.77377, 0.03, 0, 0, 1,
			0.5367, 2.45229, -3.83587, 6.56299, 0.03, 0, 0, 1,
			0.507955, 2.45229, -3.51223, 6.23621, 0.03, 0, 0, 1,
			0.480617, 2.41676, -3.30542, 5.82542, 0.03, 0, 0, 1
		);
		TRI(
			5, 1, 2,
			7, 0, 6,
			5, 2, 4,
			4, 2, 3,
			18, 3, 17,
			6, 1, 5,
			6, 0, 1,
			10, 7, 8,
			10, 8, 9,
			16, 7, 10,
			12, 10, 11,
			14, 10, 12,
			14, 12, 13,
			16, 10, 14,
			16, 14, 15,
			16, 0, 7,
			25, 3, 18,
			25, 19, 23,
			21, 19, 20,
			23, 19, 21,
			23, 21, 22,
			25, 18, 19,
			25, 23, 24,
			25, 4, 3
		);
	};
	SubObject MarkerLine_0
	{
		AlphaTest = 0.200000;
		Color = (0.930000,0.930000,0.930000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		Storage = Buffer;
		V(
			-13.6028, -4.34476, 0.01,
			-13.9028, -4.34331, 0.01,
			-13.8555, 5.42221, 0.01,
			-13.5556, 5.42076, 0.01,
			4.14424, 5.33511, 0.01,
			4.44424, 5.33366, 0.01,
			4.39698, -4.43186, 0.01,
			4.09698, -4.43041, 0.01,
			-2.80293, -4.39702, 0.01,
			-3.10293, -4.39557, 0.01,
			-3.05568, 5.36995, 0.01,
			-2.75568, 5.3685, 0.01,
			-6.65563, 5.38737, 0.01,
			-6.35564, 5.38592, 0.01,
			-6.40289, -4.3796, 0.01,
			-6.70289, -4.37815, 0.01,
			-9.89882, 1.63739, 0.01,
			-10.0488, 1.63812, 0.01,
			-10.0306, 5.4037, 0.01,
			-9.8806, 5.40297, 0.01,
			0.44025, -0.64704, 0.01,
			0.590248, -0.647766, 0.01,
			0.572026, -4.41335, 0.01,
			0.422028, -4.41262, 0.01 
		);
		TRI(
			  0,  1,  3,
			  1,  2,  3,
			  4,  5,  7,
			  5,  6,  7,
			  8,  9, 11,
			  9, 10, 11,
			 12, 13, 15,
			 13, 14, 15,
			 16, 17, 19,
			 17, 18, 19,
			 20, 21, 23,
			 21, 22, 23 
		);
	};
	SubObject ObjectStrip_0
	{
		AlphaTest = 0.200000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		Texture = SCNX.ROAD.SUPERSTRUCTURES.STRIPS.guardrail;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | ClampT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 3;
		Storage = Component;
		TVN(
			0, 1, -5.92122, -4.38193, 0.73, -0.999988, 0.00483899, 0,
			0, 0, -5.92122, -4.38193, 0.03, -0.999988, 0.00483899, 0,
			1, 0, -5.90187, -0.381975, 0.03, -0.999988, 0.00483899, 0,
			1, 1, -5.90187, -0.381975, 0.73, -0.999988, 0.00483899, 0,
			1, 0, -5.88122, -4.38212, 0.03, 0.999988, -0.00483899, 0,
			1, 1, -5.88122, -4.38212, 0.73, 0.999988, -0.00483899, 0,
			2, 1, -5.86187, -0.382169, 0.73, 0.999988, -0.00483899, 0,
			2, 0, -5.86187, -0.382169, 0.03, 0.999988, -0.00483899, 0,
			2, 1, -5.88122, -4.38212, 0.73, 2.82049e-18, 5.8286e-16, 1,
			2, 1, -5.92122, -4.38193, 0.73, 2.82049e-18, 5.8286e-16, 1,
			3, 1, -5.90187, -0.381975, 0.73, 2.82049e-18, 5.8286e-16, 1,
			3, 1, -5.86187, -0.382169, 0.73, 2.82049e-18, 5.8286e-16, 1,
			3, 1, -5.90187, -0.381975, 0.73, -0.999988, 0.00483899, 0,
			3, 0, -5.90187, -0.381975, 0.03, -0.999988, 0.00483899, 0,
			4, 0, -5.88251, 3.61798, 0.03, -0.999988, 0.00483899, 0,
			4, 1, -5.88251, 3.61798, 0.73, -0.999988, 0.00483899, 0,
			4, 0, -5.86187, -0.382169, 0.03, 0.999988, -0.00483899, 0,
			4, 1, -5.86187, -0.382169, 0.73, 0.999988, -0.00483899, 0,
			5, 1, -5.84251, 3.61778, 0.73, 0.999988, -0.00483899, 0,
			5, 0, -5.84251, 3.61778, 0.03, 0.999988, -0.00483899, 0,
			5, 1, -5.86187, -0.382169, 0.73, 0, 0, 1,
			5, 1, -5.90187, -0.381975, 0.73, 0, 0, 1,
			6, 1, -5.88251, 3.61798, 0.73, 0, 0, 1,
			6, 1, -5.84251, 3.61778, 0.73, 0, 0, 1,
			0, 1, -3.58093, 5.37249, 0.73, 0.999988, -0.00483899, 0,
			0, 0, -3.58093, 5.37249, 0.03, 0.999988, -0.00483899, 0,
			1, 0, -3.60028, 1.37254, 0.03, 0.999988, -0.00483899, 0,
			1, 1, -3.60028, 1.37254, 0.73, 0.999988, -0.00483899, 0,
			1, 0, -3.62092, 5.37268, 0.03, -0.999988, 0.00483899, 0,
			1, 1, -3.62092, 5.37268, 0.73, -0.999988, 0.00483899, 0,
			2, 1, -3.64028, 1.37273, 0.73, -0.999988, 0.00483899, 0,
			2, 0, -3.64028, 1.37273, 0.03, -0.999988, 0.00483899, 0,
			2, 1, -3.62092, 5.37268, 0.73, 1.34309e-19, 2.77553e-17, 1,
			2, 1, -3.58093, 5.37249, 0.73, 1.34309e-19, 2.77553e-17, 1,
			3, 1, -3.60028, 1.37254, 0.73, 1.34309e-19, 2.77553e-17, 1,
			3, 1, -3.64028, 1.37273, 0.73, 1.34309e-19, 2.77553e-17, 1,
			3, 1, -3.60028, 1.37254, 0.73, 0.999988, -0.00483899, 0,
			3, 0, -3.60028, 1.37254, 0.03, 0.999988, -0.00483899, 0,
			4, 0, -3.61964, -2.62742, 0.03, 0.999988, -0.00483899, 0,
			4, 1, -3.61964, -2.62742, 0.73, 0.999988, -0.00483899, 0,
			4, 0, -3.64028, 1.37273, 0.03, -0.999988, 0.00483899, 0,
			4, 1, -3.64028, 1.37273, 0.73, -0.999988, 0.00483899, 0,
			5, 1, -3.65964, -2.62722, 0.73, -0.999988, 0.00483899, 0,
			5, 0, -3.65964, -2.62722, 0.03, -0.999988, 0.00483899, 0,
			5, 1, -3.64028, 1.37273, 0.73, 0, 0, 1,
			5, 1, -3.60028, 1.37254, 0.73, 0, 0, 1,
			6, 1, -3.61964, -2.62742, 0.73, 0, 0, 1,
			6, 1, -3.65964, -2.62722, 0.73, 0, 0, 1,
			0, 1, -16.6633, -4.32995, 0.73, -0.999988, 0.00483899, 0,
			0, 0, -16.6633, -4.32995, 0.03, -0.999988, 0.00483899, 0,
			1, 0, -16.644, -0.329994, 0.03, -0.999988, 0.00483899, 0,
			1, 1, -16.644, -0.329994, 0.73, -0.999988, 0.00483899, 0,
			1, 0, -16.6233, -4.33014, 0.03, 0.999988, -0.00483899, 0,
			1, 1, -16.6233, -4.33014, 0.73, 0.999988, -0.00483899, 0,
			2, 1, -16.604, -0.330187, 0.73, 0.999988, -0.00483899, 0,
			2, 0, -16.604, -0.330187, 0.03, 0.999988, -0.00483899, 0,
			2, 1, -16.6233, -4.33014, 0.73, 0, 0, 1,
			2, 1, -16.6633, -4.32995, 0.73, 0, 0, 1,
			3, 1, -16.644, -0.329994, 0.73, 0, 0, 1,
			3, 1, -16.604, -0.330187, 0.73, 0, 0, 1,
			3, 1, -16.644, -0.329994, 0.73, -0.999988, 0.00483899, 0,
			3, 0, -16.644, -0.329994, 0.03, -0.999988, 0.00483899, 0,
			4, 0, -16.6246, 3.66996, 0.17609, -0.999988, 0.00483899, 0,
			4, 1, -16.6246, 3.66996, 0.87609, -0.999988, 0.00483899, 0,
			4, 0, -16.604, -0.330187, 0.03, 0.999988, -0.00483899, 0,
			4, 1, -16.604, -0.330187, 0.73, 0.999988, -0.00483899, 0,
			5, 1, -16.5846, 3.66977, 0.856125, 0.999988, -0.00483899, 0,
			5, 0, -16.5846, 3.66977, 0.156125, 0.999988, -0.00483899, 0,
			5, 1, -16.604, -0.330187, 0.73, -0.000176615, -0.0364978, 0.999334,
			5, 1, -16.644, -0.329994, 0.73, -0.000176615, -0.0364978, 0.999334,
			6, 1, -16.6246, 3.66996, 0.87609, -0.000176615, -0.0364978, 0.999334,
			6, 1, -16.5846, 3.66977, 0.856125, -0.000176615, -0.0364978, 0.999334,
			0, 1, 7.28249, 5.31992, 0.73, 0.999988, -0.00483899, 0,
			0, 0, 7.28249, 5.31992, 0.03, 0.999988, -0.00483899, 0,
			1, 0, 7.26314, 1.31997, 0.03, 0.999988, -0.00483899, 0,
			1, 1, 7.26314, 1.31997, 0.73, 0.999988, -0.00483899, 0,
			1, 0, 7.24249, 5.32011, 0.03, -0.999988, 0.00483899, 0,
			1, 1, 7.24249, 5.32011, 0.73, -0.999988, 0.00483899, 0,
			2, 1, 7.22314, 1.32016, 0.73, -0.999988, 0.00483899, 0,
			2, 0, 7.22314, 1.32016, 0.03, -0.999988, 0.00483899, 0,
			2, 1, 7.24249, 5.32011, 0.73, 0, 0, 1,
			2, 1, 7.28249, 5.31992, 0.73, 0, 0, 1,
			3, 1, 7.26314, 1.31997, 0.73, 0, 0, 1,
			3, 1, 7.22314, 1.32016, 0.73, 0, 0, 1,
			3, 1, 7.26314, 1.31997, 0.73, 0.999988, -0.00483899, 0,
			3, 0, 7.26314, 1.31997, 0.03, 0.999988, -0.00483899, 0,
			4, 0, 7.24378, -2.67999, 0.03, 0.999988, -0.00483899, 0,
			4, 1, 7.24378, -2.67999, 0.73, 0.999988, -0.00483899, 0,
			4, 0, 7.22314, 1.32016, 0.03, -0.999988, 0.00483899, 0,
			4, 1, 7.22314, 1.32016, 0.73, -0.999988, 0.00483899, 0,
			5, 1, 7.20378, -2.67979, 0.73, -0.999988, 0.00483899, 0,
			5, 0, 7.20378, -2.67979, 0.03, -0.999988, 0.00483899, 0,
			5, 1, 7.22314, 1.32016, 0.73, 0, 0, 1,
			5, 1, 7.26314, 1.31997, 0.73, 0, 0, 1,
			6, 1, 7.24378, -2.67999, 0.73, 0, 0, 1,
			6, 1, 7.20378, -2.67979, 0.73, 0, 0, 1,
			0, 1, 54.4927, -9.08055, 4.95334, -0.224935, -0.974374, -0,
			0, 0, 54.4927, -9.08055, 4.25334, -0.224935, -0.974374, -0,
			1, 0, 50.5824, -8.17788, 4.50207, -0.224935, -0.974374, -0,
			1, 1, 50.5824, -8.17788, 5.20207, -0.224935, -0.974374, -0,
			1, 0, 54.5015, -9.04155, 4.2526, 0.224935, 0.974374, -0,
			1, 1, 54.5015, -9.04155, 4.9526, 0.224935, 0.974374, -0,
			2, 1, 50.5915, -8.13892, 5.20141, 0.224935, 0.974374, -0,
			2, 0, 50.5915, -8.13892, 4.50141, 0.224935, 0.974374, -0,
			2, 1, 54.5015, -9.04155, 4.9526, 0.0645058, 0.00445358, 0.997907,
			2, 1, 54.4927, -9.08055, 4.95334, 0.0645058, 0.00445358, 0.997907,
			3, 1, 50.5824, -8.17788, 5.20207, 0.0645058, 0.00445358, 0.997907,
			3, 1, 50.5915, -8.13892, 5.20141, 0.0645058, 0.00445358, 0.997907,
			3, 1, 50.5824, -8.17788, 5.20207, -0.226784, -0.973945, -0,
			3, 0, 50.5824, -8.17788, 4.50207, -0.226784, -0.973945, -0,
			4, 0, 46.5937, -7.2491, 4.76221, -0.226784, -0.973945, -0,
			4, 1, 46.5937, -7.2491, 5.46221, -0.226784, -0.973945, -0,
			4, 0, 50.5915, -8.13892, 4.50141, 0.226784, 0.973945, -0,
			4, 1, 50.5915, -8.13892, 5.20141, 0.226784, 0.973945, -0,
			5, 1, 46.6027, -7.21013, 5.46218, 0.226784, 0.973945, -0,
			5, 0, 46.6027, -7.21013, 4.76218, 0.226784, 0.973945, -0,
			5, 1, 50.5915, -8.13892, 5.20141, 0.0654767, 0.00171203, 0.997853,
			5, 1, 50.5824, -8.17788, 5.20207, 0.0654767, 0.00171203, 0.997853,
			6, 1, 46.5937, -7.2491, 5.46221, 0.0654767, 0.00171203, 0.997853,
			6, 1, 46.6027, -7.21013, 5.46218, 0.0654767, 0.00171203, 0.997853,
			6, 1, 46.5937, -7.2491, 5.46221, -0.220919, -0.975292, -0,
			6, 0, 46.5937, -7.2491, 4.76221, -0.220919, -0.975292, -0,
			7, 0, 42.6171, -6.34834, 5.03616, -0.220919, -0.975292, -0,
			7, 1, 42.6171, -6.34834, 5.73616, -0.220919, -0.975292, -0,
			7, 0, 46.6027, -7.21013, 4.76218, 0.220919, 0.975292, -0,
			7, 1, 46.6027, -7.21013, 5.46218, 0.220919, 0.975292, -0,
			8, 1, 42.6257, -6.30928, 5.73639, 0.220919, 0.975292, -0,
			8, 0, 42.6257, -6.30928, 5.03639, 0.220919, 0.975292, -0,
			8, 1, 46.6027, -7.21013, 5.46218, 0.0655034, -0.0142672, 0.99775,
			8, 1, 46.5937, -7.2491, 5.46221, 0.0655034, -0.0142672, 0.99775,
			9, 1, 42.6171, -6.34834, 5.73616, 0.0655034, -0.0142672, 0.99775,
			9, 1, 42.6257, -6.30928, 5.73639, 0.0655034, -0.0142672, 0.99775,
			9, 1, 42.6171, -6.34834, 5.73616, -0.207195, -0.9783, -0,
			9, 0, 42.6171, -6.34834, 5.03616, -0.207195, -0.9783, -0,
			10, 0, 38.6462, -5.50733, 5.30016, -0.207195, -0.9783, -0,
			10, 1, 38.6462, -5.50733, 6.00016, -0.207195, -0.9783, -0,
			10, 0, 42.6257, -6.30928, 5.03639, 0.207195, 0.9783, -0,
			10, 1, 42.6257, -6.30928, 5.73639, 0.207195, 0.9783, -0,
			11, 1, 38.6541, -5.46812, 6.0005, 0.207195, 0.9783, -0,
			11, 0, 38.6541, -5.46812, 5.3005, 0.207195, 0.9783, -0,
			11, 1, 42.6257, -6.30928, 5.73639, 0.062204, -0.0195326, 0.997872,
			11, 1, 42.6171, -6.34834, 5.73616, 0.062204, -0.0195326, 0.997872,
			12, 1, 38.6462, -5.50733, 6.00016, 0.062204, -0.0195326, 0.997872,
			12, 1, 38.6541, -5.46812, 6.0005, 0.062204, -0.0195326, 0.997872,
			12, 1, 38.6462, -5.50733, 6.00016, -0.185432, -0.982657, -0,
			12, 0, 38.6462, -5.50733, 5.30016, -0.185432, -0.982657, -0,
			13, 0, 34.6759, -4.75812, 5.55214, -0.185432, -0.982657, -0,
			13, 1, 34.6759, -4.75812, 6.25214, -0.185432, -0.982657, -0,
			13, 0, 38.6541, -5.46812, 5.3005, 0.185432, 0.982657, -0,
			13, 1, 38.6541, -5.46812, 6.0005, 0.185432, 0.982657, -0,
			14, 1, 34.6828, -4.71871, 6.25208, 0.185432, 0.982657, -0,
			14, 0, 34.6828, -4.71871, 5.55208, 0.185432, 0.982657, -0,
			14, 1, 38.6541, -5.46812, 6.0005, 0.0594497, -0.020627, 0.998018,
			14, 1, 38.6462, -5.50733, 6.00016, 0.0594497, -0.020627, 0.998018,
			15, 1, 34.6759, -4.75812, 6.25214, 0.0594497, -0.020627, 0.998018,
			15, 1, 34.6828, -4.71871, 6.25208, 0.0594497, -0.020627, 0.998018,
			15, 1, 34.6759, -4.75812, 6.25214, -0.155375, -0.987855, -0,
			15, 0, 34.6759, -4.75812, 5.55214, -0.155375, -0.987855, -0,
			16, 0, 30.7035, -4.13332, 5.74862, -0.155375, -0.987855, -0,
			16, 1, 30.7035, -4.13332, 6.44862, -0.155375, -0.987855, -0,
			16, 0, 34.6828, -4.71871, 5.55208, 0.155375, 0.987856, -0,
			16, 1, 34.6828, -4.71871, 6.25208, 0.155375, 0.987856, -0,
			17, 1, 30.709, -4.0937, 6.44924, 0.155375, 0.987856, -0,
			17, 0, 30.709, -4.0937, 5.74924, 0.155375, 0.987856, -0,
			17, 1, 34.6828, -4.71871, 6.25208, 0.0483316, -0.00680133, 0.998808,
			17, 1, 34.6759, -4.75812, 6.25214, 0.0483316, -0.00680133, 0.998808,
			18, 1, 30.7035, -4.13332, 6.44862, 0.0483316, -0.00680133, 0.998808,
			18, 1, 30.709, -4.0937, 6.44924, 0.0483316, -0.00680133, 0.998808,
			18, 1, 30.7035, -4.13332, 6.44862, -0.116787, -0.993157, -0,
			18, 0, 30.7035, -4.13332, 5.74862, -0.116787, -0.993157, -0,
			19, 0, 26.729, -3.66594, 5.91668, -0.116787, -0.993157, -0,
			19, 1, 26.729, -3.66594, 6.61668, -0.116787, -0.993157, -0,
			19, 0, 30.709, -4.0937, 5.74924, 0.116787, 0.993157, -0,
			19, 1, 30.709, -4.0937, 6.44924, 0.116787, 0.993157, -0,
			20, 1, 26.7328, -3.62612, 6.61659, 0.116787, 0.993157, -0,
			20, 0, 26.7328, -3.62612, 5.91659, 0.116787, 0.993157, -0,
			20, 1, 30.709, -4.0937, 6.44924, 0.0397549, -0.0211488, 0.998986,
			20, 1, 30.7035, -4.13332, 6.44862, 0.0397549, -0.0211488, 0.998986,
			21, 1, 26.729, -3.66594, 6.61668, 0.0397549, -0.0211488, 0.998986,
			21, 1, 26.7328, -3.62612, 6.61659, 0.0397549, -0.0211488, 0.998986,
			21, 1, 26.729, -3.66594, 6.61668, -0.068936, -0.997621, -0,
			21, 0, 26.729, -3.66594, 5.91668, -0.068936, -0.997621, -0,
			22, 0, 22.659, -3.38471, 6.00086, -0.068936, -0.997621, -0,
			22, 1, 22.659, -3.38471, 6.70086, -0.068936, -0.997621, -0,
			22, 0, 26.7328, -3.62612, 5.91659, 0.0689356, 0.997621, -0,
			22, 1, 26.7328, -3.62612, 6.61659, 0.0689356, 0.997621, -0,
			23, 1, 22.6607, -3.34474, 6.70135, 0.0689356, 0.997621, -0,
			23, 0, 22.6607, -3.34474, 6.00135, 0.0689356, 0.997621, -0,
			23, 1, 26.7328, -3.62612, 6.61659, 0.0206954, 0.000249916, 0.999786,
			23, 1, 26.729, -3.66594, 6.61668, 0.0206954, 0.000249916, 0.999786,
			24, 1, 22.659, -3.38471, 6.70086, 0.0206954, 0.000249916, 0.999786,
			24, 1, 22.6607, -3.34474, 6.70135, 0.0206954, 0.000249916, 0.999786,
			0, 1, 20.1522, 4.39149, 6.73, 0.0314451, 0.999505, 0,
			0, 0, 20.1522, 4.39149, 6.03, 0.0314451, 0.999505, 0,
			1, 0, 24.18, 4.26477, 5.96194, 0.0314451, 0.999505, 0,
			1, 1, 24.18, 4.26477, 6.66194, 0.0314451, 0.999505, 0,
			1, 0, 20.152, 4.35149, 6.03, -0.0314454, -0.999505, 0,
			1, 1, 20.152, 4.35149, 6.73, -0.0314454, -0.999505, 0,
			2, 1, 24.1777, 4.22484, 6.66331, -0.0314454, -0.999505, 0,
			2, 0, 24.1777, 4.22484, 5.96331, -0.0314454, -0.999505, 0,
			2, 1, 20.152, 4.35149, 6.73, 0.0168937, -7.36837e-05, 0.999857,
			2, 1, 20.1522, 4.39149, 6.73, 0.0168937, -7.36837e-05, 0.999857,
			3, 1, 24.18, 4.26477, 6.66194, 0.0168937, -7.36837e-05, 0.999857,
			3, 1, 24.1777, 4.22484, 6.66331, 0.0168937, -7.36837e-05, 0.999857,
			3, 1, 24.18, 4.26477, 6.66194, 0.0809621, 0.996717, 0,
			3, 0, 24.18, 4.26477, 5.96194, 0.0809621, 0.996717, 0,
			4, 0, 28.1795, 3.9399, 5.87004, 0.0809621, 0.996717, 0,
			4, 1, 28.1795, 3.9399, 6.57004, 0.0809621, 0.996717, 0,
			4, 0, 24.1777, 4.22484, 5.96331, -0.0809624, -0.996717, 0,
			4, 1, 24.1777, 4.22484, 6.66331, -0.0809624, -0.996717, 0,
			5, 1, 28.1754, 3.90011, 6.57082, -0.0809624, -0.996717, 0,
			5, 0, 28.1754, 3.90011, 5.87082, -0.0809624, -0.996717, 0,
			5, 1, 24.1777, 4.22484, 6.66331, 0.0256277, 0.0328856, 0.999131,
			5, 1, 24.18, 4.26477, 6.66194, 0.0256277, 0.0328856, 0.999131,
			6, 1, 28.1795, 3.9399, 6.57004, 0.0256277, 0.0328856, 0.999131,
			6, 1, 28.1754, 3.90011, 6.57082, 0.0256277, 0.0328856, 0.999131,
			6, 1, 28.1795, 3.9399, 6.57004, 0.123634, 0.992328, 0,
			6, 0, 28.1795, 3.9399, 5.87004, 0.123634, 0.992328, 0,
			7, 0, 32.2452, 3.43336, 5.7308, 0.123634, 0.992328, 0,
			7, 1, 32.2452, 3.43336, 6.4308, 0.123634, 0.992328, 0,
			7, 0, 28.1754, 3.90011, 5.87082, -0.123634, -0.992328, 0,
			7, 1, 28.1754, 3.90011, 6.57082, -0.123634, -0.992328, 0,
			8, 1, 32.2395, 3.39377, 6.43071, -0.123634, -0.992328, 0,
			8, 0, 32.2395, 3.39377, 5.73071, -0.123634, -0.992328, 0,
			8, 1, 28.1754, 3.90011, 6.57082, 0.0361953, 0.0158501, 0.999219,
			8, 1, 28.1795, 3.9399, 6.57004, 0.0361953, 0.0158501, 0.999219,
			9, 1, 32.2452, 3.43336, 6.4308, 0.0361953, 0.0158501, 0.999219,
			9, 1, 32.2395, 3.39377, 6.43071, 0.0361953, 0.0158501, 0.999219,
			9, 1, 32.2452, 3.43336, 6.4308, 0.159082, 0.987265, 0,
			9, 0, 32.2452, 3.43336, 5.7308, 0.159082, 0.987265, 0,
			10, 0, 36.2715, 2.78458, 5.51434, 0.159082, 0.987265, 0,
			10, 1, 36.2715, 2.78458, 6.21434, 0.159082, 0.987265, 0,
			10, 0, 32.2395, 3.39377, 5.73071, -0.159082, -0.987265, 0,
			10, 1, 32.2395, 3.39377, 6.43071, -0.159082, -0.987265, 0,
			11, 1, 36.2646, 2.74519, 6.21478, -0.159082, -0.987265, 0,
			11, 0, 36.2646, 2.74519, 5.51478, -0.159082, -0.987265, 0,
			11, 1, 32.2395, 3.39377, 6.43071, 0.0521011, -0.00983662, 0.998593,
			11, 1, 32.2452, 3.43336, 6.4308, 0.0521011, -0.00983662, 0.998593,
			12, 1, 36.2715, 2.78458, 6.21434, 0.0521011, -0.00983662, 0.998593,
			12, 1, 36.2646, 2.74519, 6.21478, 0.0521011, -0.00983662, 0.998593,
			12, 1, 36.2715, 2.78458, 6.21434, 0.186806, 0.982397, 0,
			12, 0, 36.2715, 2.78458, 5.51434, 0.186806, 0.982397, 0,
			13, 0, 40.2598, 2.0262, 5.28682, 0.186806, 0.982397, 0,
			13, 1, 40.2598, 2.0262, 5.98682, 0.186806, 0.982397, 0,
			13, 0, 36.2646, 2.74519, 5.51478, -0.186806, -0.982397, 0,
			13, 1, 36.2646, 2.74519, 6.21478, -0.186806, -0.982397, 0,
			14, 1, 40.2518, 1.987, 5.98681, -0.186806, -0.982397, 0,
			14, 0, 40.2518, 1.987, 5.28681, -0.186806, -0.982397, 0,
			14, 1, 36.2646, 2.74519, 6.21478, 0.0571458, 0.000999852, 0.998365,
			14, 1, 36.2715, 2.78458, 6.21434, 0.0571458, 0.000999852, 0.998365,
			15, 1, 40.2598, 2.0262, 5.98682, 0.0571458, 0.000999852, 0.998365,
			15, 1, 40.2518, 1.987, 5.98681, 0.0571458, 0.000999852, 0.998365,
			15, 1, 40.2598, 2.0262, 5.98682, 0.207021, 0.978337, 0,
			15, 0, 40.2598, 2.0262, 5.28682, 0.207021, 0.978337, 0,
			16, 0, 44.2137, 1.18954, 5.02714, 0.207021, 0.978337, 0,
			16, 1, 44.2137, 1.18954, 5.72714, 0.207021, 0.978337, 0,
			16, 0, 40.2518, 1.987, 5.28681, -0.207021, -0.978337, 0,
			16, 1, 40.2518, 1.987, 5.98681, -0.207021, -0.978337, 0,
			17, 1, 44.2051, 1.15047, 5.7272, -0.207021, -0.978337, 0,
			17, 0, 44.2051, 1.15047, 5.0272, -0.207021, -0.978337, 0,
			17, 1, 40.2518, 1.987, 5.98681, 0.0628021, -0.0129479, 0.997942,
			17, 1, 40.2598, 2.0262, 5.98682, 0.0628021, -0.0129479, 0.997942,
			18, 1, 44.2137, 1.18954, 5.72714, 0.0628021, -0.0129479, 0.997942,
			18, 1, 44.2051, 1.15047, 5.7272, 0.0628021, -0.0129479, 0.997942,
			18, 1, 44.2137, 1.18954, 5.72714, 0.219943, 0.975513, 0,
			18, 0, 44.2137, 1.18954, 5.02714, 0.219943, 0.975513, 0,
			19, 0, 48.1386, 0.304602, 4.7647, 0.219943, 0.975513, 0,
			19, 1, 48.1386, 0.304602, 5.4647, 0.219943, 0.975513, 0,
			19, 0, 44.2051, 1.15047, 5.0272, -0.219943, -0.975513, 0,
			19, 1, 44.2051, 1.15047, 5.7272, -0.219943, -0.975513, 0,
			20, 1, 48.1297, 0.265618, 5.46479, -0.219943, -0.975513, 0,
			20, 0, 48.1297, 0.265618, 4.76479, -0.219943, -0.975513, 0,
			20, 1, 44.2051, 1.15047, 5.7272, 0.0639466, -0.012313, 0.997877,
			20, 1, 44.2137, 1.18954, 5.72714, 0.0639466, -0.012313, 0.997877,
			21, 1, 48.1386, 0.304602, 5.4647, 0.0639466, -0.012313, 0.997877,
			21, 1, 48.1297, 0.265618, 5.46479, 0.0639466, -0.012313, 0.997877,
			21, 1, 48.1386, 0.304602, 5.4647, 0.225728, 0.97419, 0,
			21, 0, 48.1386, 0.304602, 4.7647, 0.225728, 0.97419, 0,
			22, 0, 52.0409, -0.599586, 4.50125, 0.225728, 0.97419, 0,
			22, 1, 52.0409, -0.599586, 5.20125, 0.225728, 0.97419, 0,
			22, 0, 48.1297, 0.265618, 4.76479, -0.225728, -0.97419, 0,
			22, 1, 48.1297, 0.265618, 5.46479, -0.225728, -0.97419, 0,
			23, 1, 52.0318, -0.638549, 5.20128, -0.225728, -0.97419, 0,
			23, 0, 52.0318, -0.638549, 4.50128, -0.225728, -0.97419, 0,
			23, 1, 48.1297, 0.265618, 5.46479, 0.0644836, -0.0124365, 0.997841,
			23, 1, 48.1386, 0.304602, 5.4647, 0.0644836, -0.0124365, 0.997841,
			24, 1, 52.0409, -0.599586, 5.20125, 0.0644836, -0.0124365, 0.997841,
			24, 1, 52.0318, -0.638549, 5.20128, 0.0644836, -0.0124365, 0.997841,
			24, 1, 52.0409, -0.599586, 5.20125, 0.224348, 0.974509, 0,
			24, 0, 52.0409, -0.599586, 4.50125, 0.224348, 0.974509, 0,
			25, 0, 56.0239, -1.51654, 4.25469, 0.224348, 0.974509, 0,
			25, 1, 56.0239, -1.51654, 4.95469, 0.224348, 0.974509, 0,
			25, 0, 52.0318, -0.638549, 4.50128, -0.224348, -0.974509, 0,
			25, 1, 52.0318, -0.638549, 5.20128, -0.224348, -0.974509, 0,
			26, 1, 56.0151, -1.55555, 4.95444, -0.224348, -0.974509, 0,
			26, 0, 56.0151, -1.55555, 4.25444, -0.224348, -0.974509, 0,
			26, 1, 52.0318, -0.638549, 5.20128, 0.0588202, -0.0128998, 0.998185,
			26, 1, 52.0409, -0.599586, 5.20125, 0.0588202, -0.0128998, 0.998185,
			27, 1, 56.0239, -1.51654, 4.95469, 0.0588202, -0.0128998, 0.998185,
			27, 1, 56.0151, -1.55555, 4.95444, 0.0588202, -0.0128998, 0.998185,
			0, 1, -28.3114, -3.32677, 6.73, -0.0435279, -0.999052, -0,
			0, 0, -28.3114, -3.32677, 6.03, -0.0435279, -0.999052, -0,
			1, 0, -32.4093, -3.14823, 5.93869, -0.0435279, -0.999052, -0,
			1, 1, -32.4093, -3.14823, 6.63869, -0.0435279, -0.999052, -0,
			1, 0, -28.3113, -3.28677, 6.03, 0.0435287, 0.999052, -0,
			1, 1, -28.3113, -3.28677, 6.73, 0.0435287, 0.999052, -0,
			2, 1, -32.4061, -3.10836, 6.63996, 0.0435287, 0.999052, -0,
			2, 0, -32.4061, -3.10836, 5.93996, 0.0435287, 0.999052, -0,
			2, 1, -28.3113, -3.28677, 6.73, -0.0222715, 9.71397e-05, 0.999752,
			2, 1, -28.3114, -3.32677, 6.73, -0.0222715, 9.71397e-05, 0.999752,
			3, 1, -32.4093, -3.14823, 6.63869, -0.0222715, 9.71397e-05, 0.999752,
			3, 1, -32.4061, -3.10836, 6.63996, -0.0222715, 9.71397e-05, 0.999752,
			3, 1, -32.4093, -3.14823, 6.63869, -0.112127, -0.993694, -0,
			3, 0, -32.4093, -3.14823, 5.93869, -0.112127, -0.993694, -0,
			4, 0, -36.4267, -2.69491, 5.80484, -0.112127, -0.993694, -0,
			4, 1, -36.4267, -2.69491, 6.50484, -0.112127, -0.993694, -0,
			4, 0, -32.4061, -3.10836, 5.93996, 0.112128, 0.993694, -0,
			4, 1, -32.4061, -3.10836, 6.63996, 0.112128, 0.993694, -0,
			5, 1, -36.421, -2.65531, 6.5047, 0.112128, 0.993694, -0,
			5, 0, -36.421, -2.65531, 5.8047, 0.112128, 0.993694, -0,
			5, 1, -32.4061, -3.10836, 6.63996, -0.0365172, -0.0286593, 0.998922,
			5, 1, -32.4093, -3.14823, 6.63869, -0.0365172, -0.0286593, 0.998922,
			6, 1, -36.4267, -2.69491, 6.50484, -0.0365172, -0.0286593, 0.998922,
			6, 1, -36.421, -2.65531, 6.5047, -0.0365172, -0.0286593, 0.998922,
			6, 1, -36.4267, -2.69491, 6.50484, -0.165735, -0.98617, -0,
			6, 0, -36.4267, -2.69491, 5.80484, -0.165735, -0.98617, -0,
			7, 0, -40.4559, -2.01777, 5.5354, -0.165735, -0.98617, -0,
			7, 1, -40.4559, -2.01777, 6.2354, -0.165735, -0.98617, -0,
			7, 0, -36.421, -2.65531, 5.8047, 0.165736, 0.98617, -0,
			7, 1, -36.421, -2.65531, 6.5047, 0.165736, 0.98617, -0,
			8, 1, -40.4484, -1.97847, 6.23614, 0.165736, 0.98617, -0,
			8, 0, -40.4484, -1.97847, 5.53614, 0.165736, 0.98617, -0,
			8, 1, -36.421, -2.65531, 6.5047, -0.064594, 0.0126905, 0.997831,
			8, 1, -36.4267, -2.69491, 6.50484, -0.064594, 0.0126905, 0.997831,
			9, 1, -40.4559, -2.01777, 6.2354, -0.064594, 0.0126905, 0.997831,
			9, 1, -40.4484, -1.97847, 6.23614, -0.064594, 0.0126905, 0.997831,
			9, 1, -40.4559, -2.01777, 6.2354, -0.203842, -0.979004, -0,
			9, 0, -40.4559, -2.01777, 5.5354, -0.203842, -0.979004, -0,
			10, 0, -44.3935, -1.1979, 5.25045, -0.203842, -0.979004, -0,
			10, 1, -44.3935, -1.1979, 5.95045, -0.203842, -0.979004, -0,
			10, 0, -40.4484, -1.97847, 5.53614, 0.203842, 0.979004, -0,
			10, 1, -40.4484, -1.97847, 6.23614, 0.203842, 0.979004, -0,
			11, 1, -44.3848, -1.15886, 5.95038, 0.203842, 0.979004, -0,
			11, 0, -44.3848, -1.15886, 5.25038, 0.203842, 0.979004, -0,
			11, 1, -40.4484, -1.97847, 6.23614, -0.0731731, -0.00481059, 0.997308,
			11, 1, -40.4559, -2.01777, 6.2354, -0.0731731, -0.00481059, 0.997308,
			12, 1, -44.3935, -1.1979, 5.95045, -0.0731731, -0.00481059, 0.997308,
			12, 1, -44.3848, -1.15886, 5.95038, -0.0731731, -0.00481059, 0.997308,
			12, 1, -44.3935, -1.1979, 5.95045, -0.226373, -0.974041, -0,
			12, 0, -44.3935, -1.1979, 5.25045, -0.226373, -0.974041, -0,
			13, 0, -48.3489, -0.27865, 4.91116, -0.226373, -0.974041, -0,
			13, 1, -48.3489, -0.27865, 5.61116, -0.226373, -0.974041, -0,
			13, 0, -44.3848, -1.15886, 5.25038, 0.226374, 0.974041, -0,
			13, 1, -44.3848, -1.15886, 5.95038, 0.226374, 0.974041, -0,
			14, 1, -48.3396, -0.239746, 5.61117, 0.226374, 0.974041, -0,
			14, 0, -48.3396, -0.239746, 4.91117, 0.226374, 0.974041, -0,
			14, 1, -44.3848, -1.15886, 5.95038, -0.0809079, 0.0196828, 0.996527,
			14, 1, -44.3935, -1.1979, 5.95045, -0.0809079, 0.0196828, 0.996527,
			15, 1, -48.3489, -0.27865, 5.61116, -0.0809079, 0.0196828, 0.996527,
			15, 1, -48.3396, -0.239746, 5.61117, -0.0809079, 0.0196828, 0.996527,
			15, 1, -48.3489, -0.27865, 5.61116, -0.233352, -0.972392, -0,
			15, 0, -48.3489, -0.27865, 4.91116, -0.233352, -0.972392, -0,
			16, 0, -52.3314, 0.677077, 4.56946, -0.233352, -0.972392, -0,
			16, 1, -52.3314, 0.677077, 5.26946, -0.233352, -0.972392, -0,
			16, 0, -48.3396, -0.239746, 4.91117, 0.233352, 0.972392, -0,
			16, 1, -48.3396, -0.239746, 5.61117, 0.233352, 0.972392, -0,
			17, 1, -52.3222, 0.715991, 5.26951, 0.233352, 0.972392, -0,
			17, 0, -52.3222, 0.715991, 4.56951, 0.233352, 0.972392, -0,
			17, 1, -48.3396, -0.239746, 5.61117, -0.0809382, 0.0190106, 0.996538,
			17, 1, -48.3489, -0.27865, 5.61116, -0.0809382, 0.0190106, 0.996538,
			18, 1, -52.3314, 0.677077, 5.26946, -0.0809382, 0.0190106, 0.996538,
			18, 1, -52.3222, 0.715991, 5.26951, -0.0809382, 0.0190106, 0.996538,
			18, 1, -52.3314, 0.677077, 5.26946, -0.224042, -0.974579, -0,
			18, 0, -52.3314, 0.677077, 4.56946, -0.224042, -0.974579, -0,
			19, 0, -56.257, 1.57951, 4.27425, -0.224042, -0.974579, -0,
			19, 1, -56.257, 1.57951, 4.97425, -0.224042, -0.974579, -0,
			19, 0, -52.3222, 0.715991, 4.56951, 0.224042, 0.97458, -0,
			19, 1, -52.3222, 0.715991, 5.26951, 0.224042, 0.97458, -0,
			20, 1, -56.2485, 1.61859, 4.97366, 0.224042, 0.97458, -0,
			20, 0, -56.2485, 1.61859, 4.27366, 0.224042, 0.97458, -0,
			20, 1, -52.3222, 0.715991, 5.26951, -0.0713733, 0.0157803, 0.997325,
			20, 1, -52.3314, 0.677077, 5.26946, -0.0713733, 0.0157803, 0.997325,
			21, 1, -56.257, 1.57951, 4.97425, -0.0713733, 0.0157803, 0.997325,
			21, 1, -56.2485, 1.61859, 4.97366, -0.0713733, 0.0157803, 0.997325,
			0, 1, -55.6271, 9.33497, 4.9051, 0.218865, 0.975755, 0,
			0, 0, -55.6271, 9.33497, 4.2051, 0.218865, 0.975755, 0,
			1, 0, -51.6437, 8.44148, 4.48255, 0.218865, 0.975755, 0,
			1, 1, -51.6437, 8.44148, 5.18255, 0.218865, 0.975755, 0,
			1, 0, -55.6353, 9.29583, 4.20433, -0.218866, -0.975755, 0,
			1, 1, -55.6353, 9.29583, 4.90433, -0.218866, -0.975755, 0,
			2, 1, -51.6528, 8.40254, 5.18265, -0.218866, -0.975755, 0,
			2, 0, -51.6528, 8.40254, 4.48265, -0.218866, -0.975755, 0,
			2, 1, -55.6353, 9.29583, 4.90433, -0.0705688, -0.00487376, 0.997495,
			2, 1, -55.6271, 9.33497, 4.9051, -0.0705688, -0.00487376, 0.997495,
			3, 1, -51.6437, 8.44148, 5.18255, -0.0705688, -0.00487376, 0.997495,
			3, 1, -51.6528, 8.40254, 5.18265, -0.0705688, -0.00487376, 0.997495,
			3, 1, -51.6437, 8.44148, 5.18255, 0.232406, 0.972619, 0,
			3, 0, -51.6437, 8.44148, 4.48255, 0.232406, 0.972619, 0,
			4, 0, -47.7322, 7.50683, 4.81314, 0.232406, 0.972619, 0,
			4, 1, -47.7322, 7.50683, 5.51314, 0.232406, 0.972619, 0,
			4, 0, -51.6528, 8.40254, 4.48265, -0.232407, -0.972619, 0,
			4, 1, -51.6528, 8.40254, 5.18265, -0.232407, -0.972619, 0,
			5, 1, -47.7415, 7.46794, 5.51301, -0.232407, -0.972619, 0,
			5, 0, -47.7415, 7.46794, 4.81301, -0.232407, -0.972619, 0,
			5, 1, -51.6528, 8.40254, 5.18265, -0.0791509, 0.0212722, 0.996636,
			5, 1, -51.6437, 8.44148, 5.18255, -0.0791509, 0.0212722, 0.996636,
			6, 1, -47.7322, 7.50683, 5.51314, -0.0791509, 0.0212722, 0.996636,
			6, 1, -47.7415, 7.46794, 5.51301, -0.0791509, 0.0212722, 0.996636,
			6, 1, -47.7322, 7.50683, 5.51314, 0.23004, 0.973181, 0,
			6, 0, -47.7322, 7.50683, 4.81314, 0.23004, 0.973181, 0,
			7, 0, -43.7815, 6.57298, 5.15695, 0.23004, 0.973181, 0,
			7, 1, -43.7815, 6.57298, 5.85695, 0.23004, 0.973181, 0,
			7, 0, -47.7415, 7.46794, 4.81301, -0.23004, -0.973181, 0,
			7, 1, -47.7415, 7.46794, 5.51301, -0.23004, -0.973181, 0,
			8, 1, -43.7905, 6.53399, 5.85694, -0.23004, -0.973181, 0,
			8, 0, -43.7905, 6.53399, 5.15694, -0.23004, -0.973181, 0,
			8, 1, -47.7415, 7.46794, 5.51301, -0.0827917, 0.0166, 0.996429,
			8, 1, -47.7322, 7.50683, 5.51314, -0.0827917, 0.0166, 0.996429,
			9, 1, -43.7815, 6.57298, 5.85695, -0.0827917, 0.0166, 0.996429,
			9, 1, -43.7905, 6.53399, 5.85694, -0.0827917, 0.0166, 0.996429,
			9, 1, -43.7815, 6.57298, 5.85695, 0.210793, 0.977531, 0,
			9, 0, -43.7815, 6.57298, 5.15695, 0.210793, 0.977531, 0,
			10, 0, -39.7817, 5.71045, 5.48883, 0.210793, 0.977531, 0,
			10, 1, -39.7817, 5.71045, 6.18883, 0.210793, 0.977531, 0,
			10, 0, -43.7905, 6.53399, 5.15694, -0.210793, -0.977531, 0,
			10, 1, -43.7905, 6.53399, 5.85694, -0.210793, -0.977531, 0,
			11, 1, -39.7895, 5.67122, 6.18938, -0.210793, -0.977531, 0,
			11, 0, -39.7895, 5.67122, 5.48938, -0.210793, -0.977531, 0,
			11, 1, -43.7905, 6.53399, 5.85694, -0.0788698, 0.0177654, 0.996727,
			11, 1, -43.7815, 6.57298, 5.85695, -0.0788698, 0.0177654, 0.996727,
			12, 1, -39.7817, 5.71045, 6.18883, -0.0788698, 0.0177654, 0.996727,
			12, 1, -39.7895, 5.67122, 6.18938, -0.0788698, 0.0177654, 0.996727,
			12, 1, -39.7817, 5.71045, 6.18883, 0.173403, 0.984851, 0,
			12, 0, -39.7817, 5.71045, 5.48883, 0.173403, 0.984851, 0,
			13, 0, -35.8204, 5.013, 5.76926, 0.173403, 0.984851, 0,
			13, 1, -35.8204, 5.013, 6.46926, 0.173403, 0.984851, 0,
			13, 0, -39.7895, 5.67122, 5.48938, -0.173402, -0.984851, 0,
			13, 1, -39.7895, 5.67122, 6.18938, -0.173402, -0.984851, 0,
			14, 1, -35.8263, 4.97344, 6.46912, -0.173402, -0.984851, 0,
			14, 0, -35.8263, 4.97344, 5.76912, -0.173402, -0.984851, 0,
			14, 1, -39.7895, 5.67122, 6.18938, -0.0658256, 0.0271979, 0.99746,
			14, 1, -39.7817, 5.71045, 6.18883, -0.0658256, 0.0271979, 0.99746,
			15, 1, -35.8204, 5.013, 6.46926, -0.0658256, 0.0271979, 0.99746,
			15, 1, -35.8263, 4.97344, 6.46912, -0.0658256, 0.0271979, 0.99746,
			15, 1, -35.8204, 5.013, 6.46926, 0.116348, 0.993208, 0,
			15, 0, -35.8204, 5.013, 5.76926, 0.116348, 0.993208, 0,
			16, 0, -31.8035, 4.54243, 5.94778, 0.116348, 0.993208, 0,
			16, 1, -31.8035, 4.54243, 6.64778, 0.116348, 0.993208, 0,
			16, 0, -35.8263, 4.97344, 5.76912, -0.116347, -0.993209, 0,
			16, 1, -35.8263, 4.97344, 6.46912, -0.116347, -0.993209, 0,
			17, 1, -31.8067, 4.50256, 6.64871, -0.116347, -0.993209, 0,
			17, 0, -31.8067, 4.50256, 5.94871, -0.116347, -0.993209, 0,
			17, 1, -35.8263, 4.97344, 6.46912, -0.0440301, 0.00313271, 0.999025,
			17, 1, -35.8204, 5.013, 6.46926, -0.0440301, 0.00313271, 0.999025,
			18, 1, -31.8035, 4.54243, 6.64778, -0.0440301, 0.00313271, 0.999025,
			18, 1, -31.8067, 4.50256, 6.64871, -0.0440301, 0.00313271, 0.999025 
		);
		TRI(
			  0,  1,  3,
			  1,  2,  3,
			  4,  5,  7,
			  5,  6,  7,
			  8,  9, 11,
			  9, 10, 11,
			 12, 13, 15,
			 13, 14, 15,
			 16, 17, 19,
			 17, 18, 19,
			 20, 21, 23,
			 21, 22, 23,
			 24, 25, 27,
			 25, 26, 27,
			 28, 29, 31,
			 29, 30, 31,
			 32, 33, 35,
			 33, 34, 35,
			 36, 37, 39,
			 37, 38, 39,
			 40, 41, 43,
			 41, 42, 43,
			 44, 45, 47,
			 45, 46, 47,
			 48, 49, 51,
			 49, 50, 51,
			 52, 53, 55,
			 53, 54, 55,
			 56, 57, 59,
			 57, 58, 59,
			 60, 61, 63,
			 61, 62, 63,
			 64, 65, 67,
			 65, 66, 67,
			 68, 69, 71,
			 69, 70, 71,
			 72, 73, 75,
			 73, 74, 75,
			 76, 77, 79,
			 77, 78, 79,
			 80, 81, 83,
			 81, 82, 83,
			 84, 85, 87,
			 85, 86, 87,
			 88, 89, 91,
			 89, 90, 91,
			 92, 93, 95,
			 93, 94, 95,
			 96, 97, 99,
			 97, 98, 99,
			100,101,103,
			101,102,103,
			104,105,107,
			105,106,107,
			108,109,111,
			109,110,111,
			112,113,115,
			113,114,115,
			116,117,119,
			117,118,119,
			120,121,123,
			121,122,123,
			124,125,127,
			125,126,127,
			128,129,131,
			129,130,131,
			132,133,135,
			133,134,135,
			136,137,139,
			137,138,139,
			140,141,143,
			141,142,143,
			144,145,147,
			145,146,147,
			148,149,151,
			149,150,151,
			152,153,155,
			153,154,155,
			156,157,159,
			157,158,159,
			160,161,163,
			161,162,163,
			164,165,167,
			165,166,167,
			168,169,171,
			169,170,171,
			172,173,175,
			173,174,175,
			176,177,179,
			177,178,179,
			180,181,183,
			181,182,183,
			184,185,187,
			185,186,187,
			188,189,191,
			189,190,191,
			192,193,195,
			193,194,195,
			196,197,199,
			197,198,199,
			200,201,203,
			201,202,203,
			204,205,207,
			205,206,207,
			208,209,211,
			209,210,211,
			212,213,215,
			213,214,215,
			216,217,219,
			217,218,219,
			220,221,223,
			221,222,223,
			224,225,227,
			225,226,227,
			228,229,231,
			229,230,231,
			232,233,235,
			233,234,235,
			236,237,239,
			237,238,239,
			240,241,243,
			241,242,243,
			244,245,247,
			245,246,247,
			248,249,251,
			249,250,251,
			252,253,255,
			253,254,255,
			256,257,259,
			257,258,259,
			260,261,263,
			261,262,263,
			264,265,267,
			265,266,267,
			268,269,271,
			269,270,271,
			272,273,275,
			273,274,275,
			276,277,279,
			277,278,279,
			280,281,283,
			281,282,283,
			284,285,287,
			285,286,287,
			288,289,291,
			289,290,291,
			292,293,295,
			293,294,295,
			296,297,299,
			297,298,299,
			300,301,303,
			301,302,303,
			304,305,307,
			305,306,307,
			308,309,311,
			309,310,311,
			312,313,315,
			313,314,315,
			316,317,319,
			317,318,319,
			320,321,323,
			321,322,323,
			324,325,327,
			325,326,327,
			328,329,331,
			329,330,331,
			332,333,335,
			333,334,335,
			336,337,339,
			337,338,339,
			340,341,343,
			341,342,343,
			344,345,347,
			345,346,347,
			348,349,351,
			349,350,351,
			352,353,355,
			353,354,355,
			356,357,359,
			357,358,359,
			360,361,363,
			361,362,363,
			364,365,367,
			365,366,367,
			368,369,371,
			369,370,371,
			372,373,375,
			373,374,375,
			376,377,379,
			377,378,379,
			380,381,383,
			381,382,383,
			384,385,387,
			385,386,387,
			388,389,391,
			389,390,391,
			392,393,395,
			393,394,395,
			396,397,399,
			397,398,399,
			400,401,403,
			401,402,403,
			404,405,407,
			405,406,407,
			408,409,411,
			409,410,411,
			412,413,415,
			413,414,415,
			416,417,419,
			417,418,419,
			420,421,423,
			421,422,423,
			424,425,427,
			425,426,427,
			428,429,431,
			429,430,431,
			432,433,435,
			433,434,435,
			436,437,439,
			437,438,439,
			440,441,443,
			441,442,443,
			444,445,447,
			445,446,447,
			448,449,451,
			449,450,451,
			452,453,455,
			453,454,455 
		);
	};
	SubObject ObjectStrip_1
	{
		AlphaTest = 0.200000;
		Color = (1.000000,1.000000,1.000000,1.000000);
		Culling = CCW;
		DepthTest = 1;
		Fog = 1;
		Translate = <0,0,0>;
		Rotate = <0,0,0>;
		Scale = <1,1,1>;
		RenderClass = ZBuffered;
		ShadeMode = Smooth;
		Show = true;
		VisTest = true;
		Blend = false;
		Texture = SCNX.ROAD.SUPERSTRUCTURES.STRIPS.bridge_railing;
		TextureFilter = MagLinear | MinLinearMipMapLinear | TextureMipMap | RepeatS | ClampT;
		TextureBaseLevel = 0;
		TextureMaxLevel = 1000;
		TextureMaxLod = 1000;
		TextureMinLod = -1000;
		TextureAnisotropy = 3;
		Storage = Component;
		TVN(
			0, 1, -28.2758, 4.84469, 6.83, 0.00436158, 0.99999, 0,
			0, 0, -28.2758, 4.84469, 6.03, 0.00436158, 0.99999, 0,
			1, 0, -26.7758, 4.83815, 6.03, 0.00436158, 0.99999, 0,
			1, 1, -26.7758, 4.83815, 6.83, 0.00436158, 0.99999, 0,
			1, 0, -28.276, 4.80469, 6.03, -0.00436158, -0.99999, 0,
			1, 1, -28.276, 4.80469, 6.83, -0.00436158, -0.99999, 0,
			2, 1, -26.776, 4.79815, 6.83, -0.00436158, -0.99999, 0,
			2, 0, -26.776, 4.79815, 6.03, -0.00436158, -0.99999, 0,
			2, 1, -28.276, 4.80469, 6.83, 0, 0, 1,
			2, 1, -28.2758, 4.84469, 6.83, 0, 0, 1,
			3, 1, -26.7758, 4.83815, 6.83, 0, 0, 1,
			3, 1, -26.776, 4.79815, 6.83, 0, 0, 1,
			3, 1, -26.7758, 4.83815, 6.83, 0.00436158, 0.99999, 0,
			3, 0, -26.7758, 4.83815, 6.03, 0.00436158, 0.99999, 0,
			4, 0, -25.2758, 4.8316, 6.03, 0.00436158, 0.99999, 0,
			4, 1, -25.2758, 4.8316, 6.83, 0.00436158, 0.99999, 0,
			4, 0, -26.776, 4.79815, 6.03, -0.00436158, -0.99999, 0,
			4, 1, -26.776, 4.79815, 6.83, -0.00436158, -0.99999, 0,
			5, 1, -25.276, 4.7916, 6.83, -0.00436158, -0.99999, 0,
			5, 0, -25.276, 4.7916, 6.03, -0.00436158, -0.99999, 0,
			5, 1, -26.776, 4.79815, 6.83, 0, 0, 1,
			5, 1, -26.7758, 4.83815, 6.83, 0, 0, 1,
			6, 1, -25.2758, 4.8316, 6.83, 0, 0, 1,
			6, 1, -25.276, 4.7916, 6.83, 0, 0, 1,
			6, 1, -25.2758, 4.8316, 6.83, 0.00436158, 0.99999, 0,
			6, 0, -25.2758, 4.8316, 6.03, 0.00436158, 0.99999, 0,
			7, 0, -23.7758, 4.82506, 6.03, 0.00436158, 0.99999, 0,
			7, 1, -23.7758, 4.82506, 6.83, 0.00436158, 0.99999, 0,
			7, 0, -25.276, 4.7916, 6.03, -0.00436158, -0.99999, 0,
			7, 1, -25.276, 4.7916, 6.83, -0.00436158, -0.99999, 0,
			8, 1, -23.776, 4.78506, 6.83, -0.00436158, -0.99999, 0,
			8, 0, -23.776, 4.78506, 6.03, -0.00436158, -0.99999, 0,
			8, 1, -25.276, 4.7916, 6.83, 0, 0, 1,
			8, 1, -25.2758, 4.8316, 6.83, 0, 0, 1,
			9, 1, -23.7758, 4.82506, 6.83, 0, 0, 1,
			9, 1, -23.776, 4.78506, 6.83, 0, 0, 1,
			9, 1, -23.7758, 4.82506, 6.83, 0.00436158, 0.99999, 0,
			9, 0, -23.7758, 4.82506, 6.03, 0.00436158, 0.99999, 0,
			10, 0, -22.1759, 4.81808, 6.03, 0.00436158, 0.99999, 0,
			10, 1, -22.1759, 4.81808, 6.83, 0.00436158, 0.99999, 0,
			10, 0, -23.776, 4.78506, 6.03, -0.00436158, -0.99999, 0,
			10, 1, -23.776, 4.78506, 6.83, -0.00436158, -0.99999, 0,
			11, 1, -22.176, 4.77808, 6.83, -0.00436158, -0.99999, 0,
			11, 0, -22.176, 4.77808, 6.03, -0.00436158, -0.99999, 0,
			11, 1, -23.776, 4.78506, 6.83, 0, 0, 1,
			11, 1, -23.7758, 4.82506, 6.83, 0, 0, 1,
			12, 1, -22.1759, 4.81808, 6.83, 0, 0, 1,
			12, 1, -22.176, 4.77808, 6.83, 0, 0, 1,
			12, 1, -22.1759, 4.81808, 6.83, 0.00436158, 0.99999, 0,
			12, 0, -22.1759, 4.81808, 6.03, 0.00436158, 0.99999, 0,
			13, 0, -20.6759, 4.81154, 6.03, 0.00436158, 0.99999, 0,
			13, 1, -20.6759, 4.81154, 6.83, 0.00436158, 0.99999, 0,
			13, 0, -22.176, 4.77808, 6.03, -0.00436158, -0.99999, 0,
			13, 1, -22.176, 4.77808, 6.83, -0.00436158, -0.99999, 0,
			14, 1, -20.6761, 4.77154, 6.83, -0.00436158, -0.99999, 0,
			14, 0, -20.6761, 4.77154, 6.03, -0.00436158, -0.99999, 0,
			14, 1, -22.176, 4.77808, 6.83, 0, 0, 1,
			14, 1, -22.1759, 4.81808, 6.83, 0, 0, 1,
			15, 1, -20.6759, 4.81154, 6.83, 0, 0, 1,
			15, 1, -20.6761, 4.77154, 6.83, 0, 0, 1,
			15, 1, -20.6759, 4.81154, 6.83, 0.00436158, 0.99999, 0,
			15, 0, -20.6759, 4.81154, 6.03, 0.00436158, 0.99999, 0,
			16, 0, -19.1759, 4.805, 6.03, 0.00436158, 0.99999, 0,
			16, 1, -19.1759, 4.805, 6.83, 0.00436158, 0.99999, 0,
			16, 0, -20.6761, 4.77154, 6.03, -0.00436158, -0.99999, 0,
			16, 1, -20.6761, 4.77154, 6.83, -0.00436158, -0.99999, 0,
			17, 1, -19.1761, 4.765, 6.83, -0.00436158, -0.99999, 0,
			17, 0, -19.1761, 4.765, 6.03, -0.00436158, -0.99999, 0,
			17, 1, -20.6761, 4.77154, 6.83, 0, 0, 1,
			17, 1, -20.6759, 4.81154, 6.83, 0, 0, 1,
			18, 1, -19.1759, 4.805, 6.83, 0, 0, 1,
			18, 1, -19.1761, 4.765, 6.83, 0, 0, 1,
			18, 1, -19.1759, 4.805, 6.83, 0.00436158, 0.99999, 0,
			18, 0, -19.1759, 4.805, 6.03, 0.00436158, 0.99999, 0,
			19, 0, -17.6759, 4.79845, 6.03, 0.00436158, 0.99999, 0,
			19, 1, -17.6759, 4.79845, 6.83, 0.00436158, 0.99999, 0,
			19, 0, -19.1761, 4.765, 6.03, -0.00436158, -0.99999, 0,
			19, 1, -19.1761, 4.765, 6.83, -0.00436158, -0.99999, 0,
			20, 1, -17.6761, 4.75846, 6.83, -0.00436158, -0.99999, 0,
			20, 0, -17.6761, 4.75846, 6.03, -0.00436158, -0.99999, 0,
			20, 1, -19.1761, 4.765, 6.83, 0, 0, 1,
			20, 1, -19.1759, 4.805, 6.83, 0, 0, 1,
			21, 1, -17.6759, 4.79845, 6.83, 0, 0, 1,
			21, 1, -17.6761, 4.75846, 6.83, 0, 0, 1,
			21, 1, -17.6759, 4.79845, 6.83, 0.00436158, 0.99999, 0,
			21, 0, -17.6759, 4.79845, 6.03, 0.00436158, 0.99999, 0,
			22, 0, -16.0759, 4.79148, 6.03, 0.00436158, 0.99999, 0,
			22, 1, -16.0759, 4.79148, 6.83, 0.00436158, 0.99999, 0,
			22, 0, -17.6761, 4.75846, 6.03, -0.00436158, -0.99999, 0,
			22, 1, -17.6761, 4.75846, 6.83, -0.00436158, -0.99999, 0,
			23, 1, -16.0761, 4.75148, 6.83, -0.00436158, -0.99999, 0,
			23, 0, -16.0761, 4.75148, 6.03, -0.00436158, -0.99999, 0,
			23, 1, -17.6761, 4.75846, 6.83, 0, 0, 1,
			23, 1, -17.6759, 4.79845, 6.83, 0, 0, 1,
			24, 1, -16.0759, 4.79148, 6.83, 0, 0, 1,
			24, 1, -16.0761, 4.75148, 6.83, 0, 0, 1,
			24, 1, -16.0759, 4.79148, 6.83, 0.00436158, 0.99999, 0,
			24, 0, -16.0759, 4.79148, 6.03, 0.00436158, 0.99999, 0,
			25, 0, -14.5759, 4.78493, 6.03, 0.00436158, 0.99999, 0,
			25, 1, -14.5759, 4.78493, 6.83, 0.00436158, 0.99999, 0,
			25, 0, -16.0761, 4.75148, 6.03, -0.00436158, -0.99999, 0,
			25, 1, -16.0761, 4.75148, 6.83, -0.00436158, -0.99999, 0,
			26, 1, -14.5761, 4.74493, 6.83, -0.00436158, -0.99999, 0,
			26, 0, -14.5761, 4.74493, 6.03, -0.00436158, -0.99999, 0,
			26, 1, -16.0761, 4.75148, 6.83, 0, 0, 1,
			26, 1, -16.0759, 4.79148, 6.83, 0, 0, 1,
			27, 1, -14.5759, 4.78493, 6.83, 0, 0, 1,
			27, 1, -14.5761, 4.74493, 6.83, 0, 0, 1,
			27, 1, -14.5759, 4.78493, 6.83, 0.00436158, 0.99999, 0,
			27, 0, -14.5759, 4.78493, 6.03, 0.00436158, 0.99999, 0,
			28, 0, -12.976, 4.77796, 6.03, 0.00436158, 0.99999, 0,
			28, 1, -12.976, 4.77796, 6.83, 0.00436158, 0.99999, 0,
			28, 0, -14.5761, 4.74493, 6.03, -0.00436158, -0.99999, 0,
			28, 1, -14.5761, 4.74493, 6.83, -0.00436158, -0.99999, 0,
			29, 1, -12.9761, 4.73796, 6.83, -0.00436158, -0.99999, 0,
			29, 0, -12.9761, 4.73796, 6.03, -0.00436158, -0.99999, 0,
			29, 1, -14.5761, 4.74493, 6.83, 0, 0, 1,
			29, 1, -14.5759, 4.78493, 6.83, 0, 0, 1,
			30, 1, -12.976, 4.77796, 6.83, 0, 0, 1,
			30, 1, -12.9761, 4.73796, 6.83, 0, 0, 1,
			30, 1, -12.976, 4.77796, 6.83, 0.00436158, 0.99999, 0,
			30, 0, -12.976, 4.77796, 6.03, 0.00436158, 0.99999, 0,
			31, 0, -11.476, 4.77141, 6.03, 0.00436158, 0.99999, 0,
			31, 1, -11.476, 4.77141, 6.83, 0.00436158, 0.99999, 0,
			31, 0, -12.9761, 4.73796, 6.03, -0.00436158, -0.99999, 0,
			31, 1, -12.9761, 4.73796, 6.83, -0.00436158, -0.99999, 0,
			32, 1, -11.4761, 4.73141, 6.83, -0.00436158, -0.99999, 0,
			32, 0, -11.4761, 4.73141, 6.03, -0.00436158, -0.99999, 0,
			32, 1, -12.9761, 4.73796, 6.83, 0, 0, 1,
			32, 1, -12.976, 4.77796, 6.83, 0, 0, 1,
			33, 1, -11.476, 4.77141, 6.83, 0, 0, 1,
			33, 1, -11.4761, 4.73141, 6.83, 0, 0, 1,
			33, 1, -11.476, 4.77141, 6.83, 0.00436158, 0.99999, 0,
			33, 0, -11.476, 4.77141, 6.03, 0.00436158, 0.99999, 0,
			34, 0, -9.97598, 4.76487, 6.03, 0.00436158, 0.99999, 0,
			34, 1, -9.97598, 4.76487, 6.83, 0.00436158, 0.99999, 0,
			34, 0, -11.4761, 4.73141, 6.03, -0.00436158, -0.99999, 0,
			34, 1, -11.4761, 4.73141, 6.83, -0.00436158, -0.99999, 0,
			35, 1, -9.97615, 4.72487, 6.83, -0.00436158, -0.99999, 0,
			35, 0, -9.97615, 4.72487, 6.03, -0.00436158, -0.99999, 0,
			35, 1, -11.4761, 4.73141, 6.83, 0, 0, 1,
			35, 1, -11.476, 4.77141, 6.83, 0, 0, 1,
			36, 1, -9.97598, 4.76487, 6.83, 0, 0, 1,
			36, 1, -9.97615, 4.72487, 6.83, 0, 0, 1,
			36, 1, -9.97598, 4.76487, 6.83, 0.00436158, 0.99999, 0,
			36, 0, -9.97598, 4.76487, 6.03, 0.00436158, 0.99999, 0,
			37, 0, -8.47599, 4.75833, 6.03, 0.00436158, 0.99999, 0,
			37, 1, -8.47599, 4.75833, 6.83, 0.00436158, 0.99999, 0,
			37, 0, -9.97615, 4.72487, 6.03, -0.00436158, -0.99999, 0,
			37, 1, -9.97615, 4.72487, 6.83, -0.00436158, -0.99999, 0,
			38, 1, -8.47617, 4.71833, 6.83, -0.00436158, -0.99999, 0,
			38, 0, -8.47617, 4.71833, 6.03, -0.00436158, -0.99999, 0,
			38, 1, -9.97615, 4.72487, 6.83, 0, 0, 1,
			38, 1, -9.97598, 4.76487, 6.83, 0, 0, 1,
			39, 1, -8.47599, 4.75833, 6.83, 0, 0, 1,
			39, 1, -8.47617, 4.71833, 6.83, 0, 0, 1,
			39, 1, -8.47599, 4.75833, 6.83, 0.00436158, 0.99999, 0,
			39, 0, -8.47599, 4.75833, 6.03, 0.00436158, 0.99999, 0,
			40, 0, -6.87601, 4.75135, 6.03, 0.00436158, 0.99999, 0,
			40, 1, -6.87601, 4.75135, 6.83, 0.00436158, 0.99999, 0,
			40, 0, -8.47617, 4.71833, 6.03, -0.00436158, -0.99999, 0,
			40, 1, -8.47617, 4.71833, 6.83, -0.00436158, -0.99999, 0,
			41, 1, -6.87618, 4.71135, 6.83, -0.00436158, -0.99999, 0,
			41, 0, -6.87618, 4.71135, 6.03, -0.00436158, -0.99999, 0,
			41, 1, -8.47617, 4.71833, 6.83, 0, 0, 1,
			41, 1, -8.47599, 4.75833, 6.83, 0, 0, 1,
			42, 1, -6.87601, 4.75135, 6.83, 0, 0, 1,
			42, 1, -6.87618, 4.71135, 6.83, 0, 0, 1,
			42, 1, -6.87601, 4.75135, 6.83, 0.00436158, 0.99999, 0,
			42, 0, -6.87601, 4.75135, 6.03, 0.00436158, 0.99999, 0,
			43, 0, -5.37602, 4.74481, 6.03, 0.00436158, 0.99999, 0,
			43, 1, -5.37602, 4.74481, 6.83, 0.00436158, 0.99999, 0,
			43, 0, -6.87618, 4.71135, 6.03, -0.00436158, -0.99999, 0,
			43, 1, -6.87618, 4.71135, 6.83, -0.00436158, -0.99999, 0,
			44, 1, -5.3762, 4.70481, 6.83, -0.00436158, -0.99999, 0,
			44, 0, -5.3762, 4.70481, 6.03, -0.00436158, -0.99999, 0,
			44, 1, -6.87618, 4.71135, 6.83, 0, 0, 1,
			44, 1, -6.87601, 4.75135, 6.83, 0, 0, 1,
			45, 1, -5.37602, 4.74481, 6.83, 0, 0, 1,
			45, 1, -5.3762, 4.70481, 6.83, 0, 0, 1,
			45, 1, -5.37602, 4.74481, 6.83, 0.00436158, 0.99999, 0,
			45, 0, -5.37602, 4.74481, 6.03, 0.00436158, 0.99999, 0,
			46, 0, -3.77604, 4.73783, 6.03, 0.00436158, 0.99999, 0,
			46, 1, -3.77604, 4.73783, 6.83, 0.00436158, 0.99999, 0,
			46, 0, -5.3762, 4.70481, 6.03, -0.00436158, -0.99999, 0,
			46, 1, -5.3762, 4.70481, 6.83, -0.00436158, -0.99999, 0,
			47, 1, -3.77621, 4.69783, 6.83, -0.00436158, -0.99999, 0,
			47, 0, -3.77621, 4.69783, 6.03, -0.00436158, -0.99999, 0,
			47, 1, -5.3762, 4.70481, 6.83, 0, 0, 1,
			47, 1, -5.37602, 4.74481, 6.83, 0, 0, 1,
			48, 1, -3.77604, 4.73783, 6.83, 0, 0, 1,
			48, 1, -3.77621, 4.69783, 6.83, 0, 0, 1,
			48, 1, -3.77604, 4.73783, 6.83, 0.00436158, 0.99999, 0,
			48, 0, -3.77604, 4.73783, 6.03, 0.00436158, 0.99999, 0,
			49, 0, -2.17605, 4.73085, 6.03, 0.00436158, 0.99999, 0,
			49, 1, -2.17605, 4.73085, 6.83, 0.00436158, 0.99999, 0,
			49, 0, -3.77621, 4.69783, 6.03, -0.00436158, -0.99999, 0,
			49, 1, -3.77621, 4.69783, 6.83, -0.00436158, -0.99999, 0,
			50, 1, -2.17623, 4.69085, 6.83, -0.00436158, -0.99999, 0,
			50, 0, -2.17623, 4.69085, 6.03, -0.00436158, -0.99999, 0,
			50, 1, -3.77621, 4.69783, 6.83, 0, 0, 1,
			50, 1, -3.77604, 4.73783, 6.83, 0, 0, 1,
			51, 1, -2.17605, 4.73085, 6.83, 0, 0, 1,
			51, 1, -2.17623, 4.69085, 6.83, 0, 0, 1,
			51, 1, -2.17605, 4.73085, 6.83, 0.00436158, 0.99999, 0,
			51, 0, -2.17605, 4.73085, 6.03, 0.00436158, 0.99999, 0,
			52, 0, -0.676067, 4.72431, 6.03, 0.00436158, 0.99999, 0,
			52, 1, -0.676067, 4.72431, 6.83, 0.00436158, 0.99999, 0,
			52, 0, -2.17623, 4.69085, 6.03, -0.00436158, -0.99999, 0,
			52, 1, -2.17623, 4.69085, 6.83, -0.00436158, -0.99999, 0,
			53, 1, -0.676242, 4.68431, 6.83, -0.00436158, -0.99999, 0,
			53, 0, -0.676242, 4.68431, 6.03, -0.00436158, -0.99999, 0,
			53, 1, -2.17623, 4.69085, 6.83, 0, 0, 1,
			53, 1, -2.17605, 4.73085, 6.83, 0, 0, 1,
			54, 1, -0.676067, 4.72431, 6.83, 0, 0, 1,
			54, 1, -0.676242, 4.68431, 6.83, 0, 0, 1,
			54, 1, -0.676067, 4.72431, 6.83, 0.00436158, 0.99999, 0,
			54, 0, -0.676067, 4.72431, 6.03, 0.00436158, 0.99999, 0,
			55, 0, 0.923918, 4.71733, 6.03, 0.00436158, 0.99999, 0,
			55, 1, 0.923918, 4.71733, 6.83, 0.00436158, 0.99999, 0,
			55, 0, -0.676242, 4.68431, 6.03, -0.00436158, -0.99999, 0,
			55, 1, -0.676242, 4.68431, 6.83, -0.00436158, -0.99999, 0,
			56, 1, 0.923743, 4.67733, 6.83, -0.00436158, -0.99999, 0,
			56, 0, 0.923743, 4.67733, 6.03, -0.00436158, -0.99999, 0,
			56, 1, -0.676242, 4.68431, 6.83, 0, 0, 1,
			56, 1, -0.676067, 4.72431, 6.83, 0, 0, 1,
			57, 1, 0.923918, 4.71733, 6.83, 0, 0, 1,
			57, 1, 0.923743, 4.67733, 6.83, 0, 0, 1,
			57, 1, 0.923918, 4.71733, 6.83, 0.00436158, 0.99999, 0,
			57, 0, 0.923918, 4.71733, 6.03, 0.00436158, 0.99999, 0,
			58, 0, 2.5239, 4.71035, 6.03, 0.00436158, 0.99999, 0,
			58, 1, 2.5239, 4.71035, 6.83, 0.00436158, 0.99999, 0,
			58, 0, 0.923743, 4.67733, 6.03, -0.00436158, -0.99999, 0,
			58, 1, 0.923743, 4.67733, 6.83, -0.00436158, -0.99999, 0,
			59, 1, 2.52373, 4.67035, 6.83, -0.00436158, -0.99999, 0,
			59, 0, 2.52373, 4.67035, 6.03, -0.00436158, -0.99999, 0,
			59, 1, 0.923743, 4.67733, 6.83, 0, 0, 1,
			59, 1, 0.923918, 4.71733, 6.83, 0, 0, 1,
			60, 1, 2.5239, 4.71035, 6.83, 0, 0, 1,
			60, 1, 2.52373, 4.67035, 6.83, 0, 0, 1,
			60, 1, 2.5239, 4.71035, 6.83, 0.00436158, 0.99999, 0,
			60, 0, 2.5239, 4.71035, 6.03, 0.00436158, 0.99999, 0,
			61, 0, 4.02389, 4.70381, 6.03, 0.00436158, 0.99999, 0,
			61, 1, 4.02389, 4.70381, 6.83, 0.00436158, 0.99999, 0,
			61, 0, 2.52373, 4.67035, 6.03, -0.00436158, -0.99999, 0,
			61, 1, 2.52373, 4.67035, 6.83, -0.00436158, -0.99999, 0,
			62, 1, 4.02371, 4.66381, 6.83, -0.00436158, -0.99999, 0,
			62, 0, 4.02371, 4.66381, 6.03, -0.00436158, -0.99999, 0,
			62, 1, 2.52373, 4.67035, 6.83, 0, 0, 1,
			62, 1, 2.5239, 4.71035, 6.83, 0, 0, 1,
			63, 1, 4.02389, 4.70381, 6.83, 0, 0, 1,
			63, 1, 4.02371, 4.66381, 6.83, 0, 0, 1,
			63, 1, 4.02389, 4.70381, 6.83, 0.00436158, 0.99999, 0,
			63, 0, 4.02389, 4.70381, 6.03, 0.00436158, 0.99999, 0,
			64, 0, 5.62387, 4.69683, 6.03, 0.00436158, 0.99999, 0,
			64, 1, 5.62387, 4.69683, 6.83, 0.00436158, 0.99999, 0,
			64, 0, 4.02371, 4.66381, 6.03, -0.00436158, -0.99999, 0,
			64, 1, 4.02371, 4.66381, 6.83, -0.00436158, -0.99999, 0,
			65, 1, 5.6237, 4.65683, 6.83, -0.00436158, -0.99999, 0,
			65, 0, 5.6237, 4.65683, 6.03, -0.00436158, -0.99999, 0,
			65, 1, 4.02371, 4.66381, 6.83, 0, 0, 1,
			65, 1, 4.02389, 4.70381, 6.83, 0, 0, 1,
			66, 1, 5.62387, 4.69683, 6.83, 0, 0, 1,
			66, 1, 5.6237, 4.65683, 6.83, 0, 0, 1,
			66, 1, 5.62387, 4.69683, 6.83, 0.00436158, 0.99999, 0,
			66, 0, 5.62387, 4.69683, 6.03, 0.00436158, 0.99999, 0,
			67, 0, 7.22386, 4.68985, 6.03, 0.00436158, 0.99999, 0,
			67, 1, 7.22386, 4.68985, 6.83, 0.00436158, 0.99999, 0,
			67, 0, 5.6237, 4.65683, 6.03, -0.00436158, -0.99999, 0,
			67, 1, 5.6237, 4.65683, 6.83, -0.00436158, -0.99999, 0,
			68, 1, 7.22368, 4.64985, 6.83, -0.00436158, -0.99999, 0,
			68, 0, 7.22368, 4.64985, 6.03, -0.00436158, -0.99999, 0,
			68, 1, 5.6237, 4.65683, 6.83, 0, 0, 1,
			68, 1, 5.62387, 4.69683, 6.83, 0, 0, 1,
			69, 1, 7.22386, 4.68985, 6.83, 0, 0, 1,
			69, 1, 7.22368, 4.64985, 6.83, 0, 0, 1,
			69, 1, 7.22386, 4.68985, 6.83, 0.00436158, 0.99999, 0,
			69, 0, 7.22386, 4.68985, 6.03, 0.00436158, 0.99999, 0,
			70, 0, 8.72384, 4.68331, 6.03, 0.00436158, 0.99999, 0,
			70, 1, 8.72384, 4.68331, 6.83, 0.00436158, 0.99999, 0,
			70, 0, 7.22368, 4.64985, 6.03, -0.00436158, -0.99999, 0,
			70, 1, 7.22368, 4.64985, 6.83, -0.00436158, -0.99999, 0,
			71, 1, 8.72367, 4.64331, 6.83, -0.00436158, -0.99999, 0,
			71, 0, 8.72367, 4.64331, 6.03, -0.00436158, -0.99999, 0,
			71, 1, 7.22368, 4.64985, 6.83, 0, 0, 1,
			71, 1, 7.22386, 4.68985, 6.83, 0, 0, 1,
			72, 1, 8.72384, 4.68331, 6.83, 0, 0, 1,
			72, 1, 8.72367, 4.64331, 6.83, 0, 0, 1,
			72, 1, 8.72384, 4.68331, 6.83, 0.00436158, 0.99999, 0,
			72, 0, 8.72384, 4.68331, 6.03, 0.00436158, 0.99999, 0,
			73, 0, 10.3238, 4.67633, 6.03, 0.00436158, 0.99999, 0,
			73, 1, 10.3238, 4.67633, 6.83, 0.00436158, 0.99999, 0,
			73, 0, 8.72367, 4.64331, 6.03, -0.00436158, -0.99999, 0,
			73, 1, 8.72367, 4.64331, 6.83, -0.00436158, -0.99999, 0,
			74, 1, 10.3237, 4.63633, 6.83, -0.00436158, -0.99999, 0,
			74, 0, 10.3237, 4.63633, 6.03, -0.00436158, -0.99999, 0,
			74, 1, 8.72367, 4.64331, 6.83, -2.22042e-15, 9.68464e-18, 1,
			74, 1, 8.72384, 4.68331, 6.83, -2.22042e-15, 9.68464e-18, 1,
			75, 1, 10.3238, 4.67633, 6.83, -2.22042e-15, 9.68464e-18, 1,
			75, 1, 10.3237, 4.63633, 6.83, -2.22042e-15, 9.68464e-18, 1,
			75, 1, 10.3238, 4.67633, 6.83, 0.00436158, 0.99999, 0,
			75, 0, 10.3238, 4.67633, 6.03, 0.00436158, 0.99999, 0,
			76, 0, 11.8238, 4.66979, 6.03, 0.00436158, 0.99999, 0,
			76, 1, 11.8238, 4.66979, 6.83, 0.00436158, 0.99999, 0,
			76, 0, 10.3237, 4.63633, 6.03, -0.00436158, -0.99999, 0,
			76, 1, 10.3237, 4.63633, 6.83, -0.00436158, -0.99999, 0,
			77, 1, 11.8236, 4.62979, 6.83, -0.00436158, -0.99999, 0,
			77, 0, 11.8236, 4.62979, 6.03, -0.00436158, -0.99999, 0,
			77, 1, 10.3237, 4.63633, 6.83, 0, 0, 1,
			77, 1, 10.3238, 4.67633, 6.83, 0, 0, 1,
			78, 1, 11.8238, 4.66979, 6.83, 0, 0, 1,
			78, 1, 11.8236, 4.62979, 6.83, 0, 0, 1,
			78, 1, 11.8238, 4.66979, 6.83, 0.00436158, 0.99999, 0,
			78, 0, 11.8238, 4.66979, 6.03, 0.00436158, 0.99999, 0,
			79, 0, 13.4238, 4.66281, 6.03, 0.00436158, 0.99999, 0,
			79, 1, 13.4238, 4.66281, 6.83, 0.00436158, 0.99999, 0,
			79, 0, 11.8236, 4.62979, 6.03, -0.00436158, -0.99999, 0,
			79, 1, 11.8236, 4.62979, 6.83, -0.00436158, -0.99999, 0,
			80, 1, 13.4236, 4.62281, 6.83, -0.00436158, -0.99999, 0,
			80, 0, 13.4236, 4.62281, 6.03, -0.00436158, -0.99999, 0,
			80, 1, 11.8236, 4.62979, 6.83, 0, 0, 1,
			80, 1, 11.8238, 4.66979, 6.83, 0, 0, 1,
			81, 1, 13.4238, 4.66281, 6.83, 0, 0, 1,
			81, 1, 13.4236, 4.62281, 6.83, 0, 0, 1,
			81, 1, 13.4238, 4.66281, 6.83, 0.00436158, 0.99999, 0,
			81, 0, 13.4238, 4.66281, 6.03, 0.00436158, 0.99999, 0,
			82, 0, 15.0238, 4.65583, 6.03, 0.00436158, 0.99999, 0,
			82, 1, 15.0238, 4.65583, 6.83, 0.00436158, 0.99999, 0,
			82, 0, 13.4236, 4.62281, 6.03, -0.00436158, -0.99999, 0,
			82, 1, 13.4236, 4.62281, 6.83, -0.00436158, -0.99999, 0,
			83, 1, 15.0236, 4.61583, 6.83, -0.00436158, -0.99999, 0,
			83, 0, 15.0236, 4.61583, 6.03, -0.00436158, -0.99999, 0,
			83, 1, 13.4236, 4.62281, 6.83, 0, 0, 1,
			83, 1, 13.4238, 4.66281, 6.83, 0, 0, 1,
			84, 1, 15.0238, 4.65583, 6.83, 0, 0, 1,
			84, 1, 15.0236, 4.61583, 6.83, 0, 0, 1,
			84, 1, 15.0238, 4.65583, 6.83, 0.00436158, 0.99999, 0,
			84, 0, 15.0238, 4.65583, 6.03, 0.00436158, 0.99999, 0,
			85, 0, 16.5238, 4.64929, 6.03, 0.00436158, 0.99999, 0,
			85, 1, 16.5238, 4.64929, 6.83, 0.00436158, 0.99999, 0,
			85, 0, 15.0236, 4.61583, 6.03, -0.00436158, -0.99999, 0,
			85, 1, 15.0236, 4.61583, 6.83, -0.00436158, -0.99999, 0,
			86, 1, 16.5236, 4.60929, 6.83, -0.00436158, -0.99999, 0,
			86, 0, 16.5236, 4.60929, 6.03, -0.00436158, -0.99999, 0,
			86, 1, 15.0236, 4.61583, 6.83, 0, 0, 1,
			86, 1, 15.0238, 4.65583, 6.83, 0, 0, 1,
			87, 1, 16.5238, 4.64929, 6.83, 0, 0, 1,
			87, 1, 16.5236, 4.60929, 6.83, 0, 0, 1,
			87, 1, 16.5238, 4.64929, 6.83, 0.00436158, 0.99999, 0,
			87, 0, 16.5238, 4.64929, 6.03, 0.00436158, 0.99999, 0,
			88, 0, 18.1238, 4.64231, 6.03, 0.00436158, 0.99999, 0,
			88, 1, 18.1238, 4.64231, 6.83, 0.00436158, 0.99999, 0,
			88, 0, 16.5236, 4.60929, 6.03, -0.00436158, -0.99999, 0,
			88, 1, 16.5236, 4.60929, 6.83, -0.00436158, -0.99999, 0,
			89, 1, 18.1236, 4.60231, 6.83, -0.00436158, -0.99999, 0,
			89, 0, 18.1236, 4.60231, 6.03, -0.00436158, -0.99999, 0,
			89, 1, 16.5236, 4.60929, 6.83, 0, 0, 1,
			89, 1, 16.5238, 4.64929, 6.83, 0, 0, 1,
			90, 1, 18.1238, 4.64231, 6.83, 0, 0, 1,
			90, 1, 18.1236, 4.60231, 6.83, 0, 0, 1,
			90, 1, 18.1238, 4.64231, 6.83, 0.00436158, 0.99999, 0,
			90, 0, 18.1238, 4.64231, 6.03, 0.00436158, 0.99999, 0,
			91, 0, 19.6237, 4.63577, 6.03, 0.00436158, 0.99999, 0,
			91, 1, 19.6237, 4.63577, 6.83, 0.00436158, 0.99999, 0,
			91, 0, 18.1236, 4.60231, 6.03, -0.00436158, -0.99999, 0,
			91, 1, 18.1236, 4.60231, 6.83, -0.00436158, -0.99999, 0,
			92, 1, 19.6236, 4.59577, 6.83, -0.00436158, -0.99999, 0,
			92, 0, 19.6236, 4.59577, 6.03, -0.00436158, -0.99999, 0,
			92, 1, 18.1236, 4.60231, 6.83, 0, 0, 1,
			92, 1, 18.1238, 4.64231, 6.83, 0, 0, 1,
			93, 1, 19.6237, 4.63577, 6.83, 0, 0, 1,
			93, 1, 19.6236, 4.59577, 6.83, 0, 0, 1,
			0, 1, 20.1169, -3.70744, 6.83, -0.00436158, -0.99999, -0,
			0, 0, 20.1169, -3.70744, 6.03, -0.00436158, -0.99999, -0,
			1, 0, 18.6169, -3.7009, 6.03, -0.00436158, -0.99999, -0,
			1, 1, 18.6169, -3.7009, 6.83, -0.00436158, -0.99999, -0,
			1, 0, 20.117, -3.66744, 6.03, 0.00436158, 0.99999, -0,
			1, 1, 20.117, -3.66744, 6.83, 0.00436158, 0.99999, -0,
			2, 1, 18.6171, -3.6609, 6.83, 0.00436158, 0.99999, -0,
			2, 0, 18.6171, -3.6609, 6.03, 0.00436158, 0.99999, -0,
			2, 1, 20.117, -3.66744, 6.83, 0, 0, 1,
			2, 1, 20.1169, -3.70744, 6.83, 0, 0, 1,
			3, 1, 18.6169, -3.7009, 6.83, 0, 0, 1,
			3, 1, 18.6171, -3.6609, 6.83, 0, 0, 1,
			3, 1, 18.6169, -3.7009, 6.83, -0.00436158, -0.99999, -0,
			3, 0, 18.6169, -3.7009, 6.03, -0.00436158, -0.99999, -0,
			4, 0, 17.1169, -3.69436, 6.03, -0.00436158, -0.99999, -0,
			4, 1, 17.1169, -3.69436, 6.83, -0.00436158, -0.99999, -0,
			4, 0, 18.6171, -3.6609, 6.03, 0.00436158, 0.99999, -0,
			4, 1, 18.6171, -3.6609, 6.83, 0.00436158, 0.99999, -0,
			5, 1, 17.1171, -3.65436, 6.83, 0.00436158, 0.99999, -0,
			5, 0, 17.1171, -3.65436, 6.03, 0.00436158, 0.99999, -0,
			5, 1, 18.6171, -3.6609, 6.83, 0, 0, 1,
			5, 1, 18.6169, -3.7009, 6.83, 0, 0, 1,
			6, 1, 17.1169, -3.69436, 6.83, 0, 0, 1,
			6, 1, 17.1171, -3.65436, 6.83, 0, 0, 1,
			6, 1, 17.1169, -3.69436, 6.83, -0.00436158, -0.99999, -0,
			6, 0, 17.1169, -3.69436, 6.03, -0.00436158, -0.99999, -0,
			7, 0, 15.6169, -3.68782, 6.03, -0.00436158, -0.99999, -0,
			7, 1, 15.6169, -3.68782, 6.83, -0.00436158, -0.99999, -0,
			7, 0, 17.1171, -3.65436, 6.03, 0.00436158, 0.99999, -0,
			7, 1, 17.1171, -3.65436, 6.83, 0.00436158, 0.99999, -0,
			8, 1, 15.6171, -3.64782, 6.83, 0.00436158, 0.99999, -0,
			8, 0, 15.6171, -3.64782, 6.03, 0.00436158, 0.99999, -0,
			8, 1, 17.1171, -3.65436, 6.83, 0, 0, 1,
			8, 1, 17.1169, -3.69436, 6.83, 0, 0, 1,
			9, 1, 15.6169, -3.68782, 6.83, 0, 0, 1,
			9, 1, 15.6171, -3.64782, 6.83, 0, 0, 1,
			9, 1, 15.6169, -3.68782, 6.83, -0.00436158, -0.99999, -0,
			9, 0, 15.6169, -3.68782, 6.03, -0.00436158, -0.99999, -0,
			10, 0, 14.0169, -3.68084, 6.03, -0.00436158, -0.99999, -0,
			10, 1, 14.0169, -3.68084, 6.83, -0.00436158, -0.99999, -0,
			10, 0, 15.6171, -3.64782, 6.03, 0.00436158, 0.99999, -0,
			10, 1, 15.6171, -3.64782, 6.83, 0.00436158, 0.99999, -0,
			11, 1, 14.0171, -3.64084, 6.83, 0.00436158, 0.99999, -0,
			11, 0, 14.0171, -3.64084, 6.03, 0.00436158, 0.99999, -0,
			11, 1, 15.6171, -3.64782, 6.83, 0, 0, 1,
			11, 1, 15.6169, -3.68782, 6.83, 0, 0, 1,
			12, 1, 14.0169, -3.68084, 6.83, 0, 0, 1,
			12, 1, 14.0171, -3.64084, 6.83, 0, 0, 1,
			12, 1, 14.0169, -3.68084, 6.83, -0.00436158, -0.99999, -0,
			12, 0, 14.0169, -3.68084, 6.03, -0.00436158, -0.99999, -0,
			13, 0, 12.5169, -3.6743, 6.03, -0.00436158, -0.99999, -0,
			13, 1, 12.5169, -3.6743, 6.83, -0.00436158, -0.99999, -0,
			13, 0, 14.0171, -3.64084, 6.03, 0.00436158, 0.99999, -0,
			13, 1, 14.0171, -3.64084, 6.83, 0.00436158, 0.99999, -0,
			14, 1, 12.5171, -3.6343, 6.83, 0.00436158, 0.99999, -0,
			14, 0, 12.5171, -3.6343, 6.03, 0.00436158, 0.99999, -0,
			14, 1, 14.0171, -3.64084, 6.83, 0, 0, 1,
			14, 1, 14.0169, -3.68084, 6.83, 0, 0, 1,
			15, 1, 12.5169, -3.6743, 6.83, 0, 0, 1,
			15, 1, 12.5171, -3.6343, 6.83, 0, 0, 1,
			15, 1, 12.5169, -3.6743, 6.83, -0.00436158, -0.99999, -0,
			15, 0, 12.5169, -3.6743, 6.03, -0.00436158, -0.99999, -0,
			16, 0, 11.017, -3.66775, 6.03, -0.00436158, -0.99999, -0,
			16, 1, 11.017, -3.66775, 6.83, -0.00436158, -0.99999, -0,
			16, 0, 12.5171, -3.6343, 6.03, 0.00436158, 0.99999, -0,
			16, 1, 12.5171, -3.6343, 6.83, 0.00436158, 0.99999, -0,
			17, 1, 11.0171, -3.62775, 6.83, 0.00436158, 0.99999, -0,
			17, 0, 11.0171, -3.62775, 6.03, 0.00436158, 0.99999, -0,
			17, 1, 12.5171, -3.6343, 6.83, 0, 0, 1,
			17, 1, 12.5169, -3.6743, 6.83, 0, 0, 1,
			18, 1, 11.017, -3.66775, 6.83, 0, 0, 1,
			18, 1, 11.0171, -3.62775, 6.83, 0, 0, 1,
			18, 1, 11.017, -3.66775, 6.83, -0.00436158, -0.99999, -0,
			18, 0, 11.017, -3.66775, 6.03, -0.00436158, -0.99999, -0,
			19, 0, 9.41698, -3.66077, 6.03, -0.00436158, -0.99999, -0,
			19, 1, 9.41698, -3.66077, 6.83, -0.00436158, -0.99999, -0,
			19, 0, 11.0171, -3.62775, 6.03, 0.00436158, 0.99999, -0,
			19, 1, 11.0171, -3.62775, 6.83, 0.00436158, 0.99999, -0,
			20, 1, 9.41715, -3.62077, 6.83, 0.00436158, 0.99999, -0,
			20, 0, 9.41715, -3.62077, 6.03, 0.00436158, 0.99999, -0,
			20, 1, 11.0171, -3.62775, 6.83, 0, 0, 1,
			20, 1, 11.017, -3.66775, 6.83, 0, 0, 1,
			21, 1, 9.41698, -3.66077, 6.83, 0, 0, 1,
			21, 1, 9.41715, -3.62077, 6.83, 0, 0, 1,
			21, 1, 9.41698, -3.66077, 6.83, -0.00436158, -0.99999, -0,
			21, 0, 9.41698, -3.66077, 6.03, -0.00436158, -0.99999, -0,
			22, 0, 7.91699, -3.65423, 6.03, -0.00436158, -0.99999, -0,
			22, 1, 7.91699, -3.65423, 6.83, -0.00436158, -0.99999, -0,
			22, 0, 9.41715, -3.62077, 6.03, 0.00436158, 0.99999, -0,
			22, 1, 9.41715, -3.62077, 6.83, 0.00436158, 0.99999, -0,
			23, 1, 7.91716, -3.61423, 6.83, 0.00436158, 0.99999, -0,
			23, 0, 7.91716, -3.61423, 6.03, 0.00436158, 0.99999, -0,
			23, 1, 9.41715, -3.62077, 6.83, 2.36845e-15, -1.03303e-17, 1,
			23, 1, 9.41698, -3.66077, 6.83, 2.36845e-15, -1.03303e-17, 1,
			24, 1, 7.91699, -3.65423, 6.83, 2.36845e-15, -1.03303e-17, 1,
			24, 1, 7.91716, -3.61423, 6.83, 2.36845e-15, -1.03303e-17, 1,
			24, 1, 7.91699, -3.65423, 6.83, -0.00436158, -0.99999, -0,
			24, 0, 7.91699, -3.65423, 6.03, -0.00436158, -0.99999, -0,
			25, 0, 6.317, -3.64725, 6.03, -0.00436158, -0.99999, -0,
			25, 1, 6.317, -3.64725, 6.83, -0.00436158, -0.99999, -0,
			25, 0, 7.91716, -3.61423, 6.03, 0.00436158, 0.99999, -0,
			25, 1, 7.91716, -3.61423, 6.83, 0.00436158, 0.99999, -0,
			26, 1, 6.31718, -3.60725, 6.83, 0.00436158, 0.99999, -0,
			26, 0, 6.31718, -3.60725, 6.03, 0.00436158, 0.99999, -0,
			26, 1, 7.91716, -3.61423, 6.83, 3.87386e-16, 8.8817e-14, 1,
			26, 1, 7.91699, -3.65423, 6.83, 3.87386e-16, 8.8817e-14, 1,
			27, 1, 6.317, -3.64725, 6.83, 3.87386e-16, 8.8817e-14, 1,
			27, 1, 6.31718, -3.60725, 6.83, 3.87386e-16, 8.8817e-14, 1,
			27, 1, 6.317, -3.64725, 6.83, -0.00436158, -0.99999, -0,
			27, 0, 6.317, -3.64725, 6.03, -0.00436158, -0.99999, -0,
			28, 0, 4.81702, -3.64071, 6.03, -0.00436158, -0.99999, -0,
			28, 1, 4.81702, -3.64071, 6.83, -0.00436158, -0.99999, -0,
			28, 0, 6.31718, -3.60725, 6.03, 0.00436158, 0.99999, -0,
			28, 1, 6.31718, -3.60725, 6.83, 0.00436158, 0.99999, -0,
			29, 1, 4.81719, -3.60071, 6.83, 0.00436158, 0.99999, -0,
			29, 0, 4.81719, -3.60071, 6.03, 0.00436158, 0.99999, -0,
			29, 1, 6.31718, -3.60725, 6.83, 0, 0, 1,
			29, 1, 6.317, -3.64725, 6.83, 0, 0, 1,
			30, 1, 4.81702, -3.64071, 6.83, 0, 0, 1,
			30, 1, 4.81719, -3.60071, 6.83, 0, 0, 1,
			30, 1, 4.81702, -3.64071, 6.83, -0.00436158, -0.99999, -0,
			30, 0, 4.81702, -3.64071, 6.03, -0.00436158, -0.99999, -0,
			31, 0, 3.21703, -3.63373, 6.03, -0.00436158, -0.99999, -0,
			31, 1, 3.21703, -3.63373, 6.83, -0.00436158, -0.99999, -0,
			31, 0, 4.81719, -3.60071, 6.03, 0.00436158, 0.99999, -0,
			31, 1, 4.81719, -3.60071, 6.83, 0.00436158, 0.99999, -0,
			32, 1, 3.21721, -3.59373, 6.83, 0.00436158, 0.99999, -0,
			32, 0, 3.21721, -3.59373, 6.03, 0.00436158, 0.99999, -0,
			32, 1, 4.81719, -3.60071, 6.83, 0, 0, 1,
			32, 1, 4.81702, -3.64071, 6.83, 0, 0, 1,
			33, 1, 3.21703, -3.63373, 6.83, 0, 0, 1,
			33, 1, 3.21721, -3.59373, 6.83, 0, 0, 1,
			33, 1, 3.21703, -3.63373, 6.83, -0.00436158, -0.99999, -0,
			33, 0, 3.21703, -3.63373, 6.03, -0.00436158, -0.99999, -0,
			34, 0, 1.71705, -3.62719, 6.03, -0.00436158, -0.99999, -0,
			34, 1, 1.71705, -3.62719, 6.83, -0.00436158, -0.99999, -0,
			34, 0, 3.21721, -3.59373, 6.03, 0.00436158, 0.99999, -0,
			34, 1, 3.21721, -3.59373, 6.83, 0.00436158, 0.99999, -0,
			35, 1, 1.71722, -3.58719, 6.83, 0.00436158, 0.99999, -0,
			35, 0, 1.71722, -3.58719, 6.03, 0.00436158, 0.99999, -0,
			35, 1, 3.21721, -3.59373, 6.83, 0, 0, 1,
			35, 1, 3.21703, -3.63373, 6.83, 0, 0, 1,
			36, 1, 1.71705, -3.62719, 6.83, 0, 0, 1,
			36, 1, 1.71722, -3.58719, 6.83, 0, 0, 1,
			36, 1, 1.71705, -3.62719, 6.83, -0.00436158, -0.99999, -0,
			36, 0, 1.71705, -3.62719, 6.03, -0.00436158, -0.99999, -0,
			37, 0, 0.217063, -3.62065, 6.03, -0.00436158, -0.99999, -0,
			37, 1, 0.217063, -3.62065, 6.83, -0.00436158, -0.99999, -0,
			37, 0, 1.71722, -3.58719, 6.03, 0.00436158, 0.99999, -0,
			37, 1, 1.71722, -3.58719, 6.83, 0.00436158, 0.99999, -0,
			38, 1, 0.217237, -3.58065, 6.83, 0.00436158, 0.99999, -0,
			38, 0, 0.217237, -3.58065, 6.03, 0.00436158, 0.99999, -0,
			38, 1, 1.71722, -3.58719, 6.83, 0, 0, 1,
			38, 1, 1.71705, -3.62719, 6.83, 0, 0, 1,
			39, 1, 0.217063, -3.62065, 6.83, 0, 0, 1,
			39, 1, 0.217237, -3.58065, 6.83, 0, 0, 1,
			39, 1, 0.217063, -3.62065, 6.83, -0.00436158, -0.99999, -0,
			39, 0, 0.217063, -3.62065, 6.03, -0.00436158, -0.99999, -0,
			40, 0, -1.38292, -3.61367, 6.03, -0.00436158, -0.99999, -0,
			40, 1, -1.38292, -3.61367, 6.83, -0.00436158, -0.99999, -0,
			40, 0, 0.217237, -3.58065, 6.03, 0.00436158, 0.99999, -0,
			40, 1, 0.217237, -3.58065, 6.83, 0.00436158, 0.99999, -0,
			41, 1, -1.38275, -3.57367, 6.83, 0.00436158, 0.99999, -0,
			41, 0, -1.38275, -3.57367, 6.03, 0.00436158, 0.99999, -0,
			41, 1, 0.217237, -3.58065, 6.83, 0, 0, 1,
			41, 1, 0.217063, -3.62065, 6.83, 0, 0, 1,
			42, 1, -1.38292, -3.61367, 6.83, 0, 0, 1,
			42, 1, -1.38275, -3.57367, 6.83, 0, 0, 1,
			42, 1, -1.38292, -3.61367, 6.83, -0.00436158, -0.99999, -0,
			42, 0, -1.38292, -3.61367, 6.03, -0.00436158, -0.99999, -0,
			43, 0, -2.98291, -3.60669, 6.03, -0.00436158, -0.99999, -0,
			43, 1, -2.98291, -3.60669, 6.83, -0.00436158, -0.99999, -0,
			43, 0, -1.38275, -3.57367, 6.03, 0.00436158, 0.99999, -0,
			43, 1, -1.38275, -3.57367, 6.83, 0.00436158, 0.99999, -0,
			44, 1, -2.98273, -3.56669, 6.83, 0.00436158, 0.99999, -0,
			44, 0, -2.98273, -3.56669, 6.03, 0.00436158, 0.99999, -0,
			44, 1, -1.38275, -3.57367, 6.83, 0, 0, 1,
			44, 1, -1.38292, -3.61367, 6.83, 0, 0, 1,
			45, 1, -2.98291, -3.60669, 6.83, 0, 0, 1,
			45, 1, -2.98273, -3.56669, 6.83, 0, 0, 1,
			45, 1, -2.98291, -3.60669, 6.83, -0.00436158, -0.99999, -0,
			45, 0, -2.98291, -3.60669, 6.03, -0.00436158, -0.99999, -0,
			46, 0, -4.48289, -3.60015, 6.03, -0.00436158, -0.99999, -0,
			46, 1, -4.48289, -3.60015, 6.83, -0.00436158, -0.99999, -0,
			46, 0, -2.98273, -3.56669, 6.03, 0.00436158, 0.99999, -0,
			46, 1, -2.98273, -3.56669, 6.83, 0.00436158, 0.99999, -0,
			47, 1, -4.48272, -3.56015, 6.83, 0.00436158, 0.99999, -0,
			47, 0, -4.48272, -3.56015, 6.03, 0.00436158, 0.99999, -0,
			47, 1, -2.98273, -3.56669, 6.83, 0, 0, 1,
			47, 1, -2.98291, -3.60669, 6.83, 0, 0, 1,
			48, 1, -4.48289, -3.60015, 6.83, 0, 0, 1,
			48, 1, -4.48272, -3.56015, 6.83, 0, 0, 1,
			48, 1, -4.48289, -3.60015, 6.83, -0.00436158, -0.99999, -0,
			48, 0, -4.48289, -3.60015, 6.03, -0.00436158, -0.99999, -0,
			49, 0, -6.08288, -3.59317, 6.03, -0.00436158, -0.99999, -0,
			49, 1, -6.08288, -3.59317, 6.83, -0.00436158, -0.99999, -0,
			49, 0, -4.48272, -3.56015, 6.03, 0.00436158, 0.99999, -0,
			49, 1, -4.48272, -3.56015, 6.83, 0.00436158, 0.99999, -0,
			50, 1, -6.0827, -3.55317, 6.83, 0.00436158, 0.99999, -0,
			50, 0, -6.0827, -3.55317, 6.03, 0.00436158, 0.99999, -0,
			50, 1, -4.48272, -3.56015, 6.83, 0, 0, 1,
			50, 1, -4.48289, -3.60015, 6.83, 0, 0, 1,
			51, 1, -6.08288, -3.59317, 6.83, 0, 0, 1,
			51, 1, -6.0827, -3.55317, 6.83, 0, 0, 1,
			51, 1, -6.08288, -3.59317, 6.83, -0.00436158, -0.99999, -0,
			51, 0, -6.08288, -3.59317, 6.03, -0.00436158, -0.99999, -0,
			52, 0, -7.68286, -3.58619, 6.03, -0.00436158, -0.99999, -0,
			52, 1, -7.68286, -3.58619, 6.83, -0.00436158, -0.99999, -0,
			52, 0, -6.0827, -3.55317, 6.03, 0.00436158, 0.99999, -0,
			52, 1, -6.0827, -3.55317, 6.83, 0.00436158, 0.99999, -0,
			53, 1, -7.68269, -3.54619, 6.83, 0.00436158, 0.99999, -0,
			53, 0, -7.68269, -3.54619, 6.03, 0.00436158, 0.99999, -0,
			53, 1, -6.0827, -3.55317, 6.83, 0, 0, 1,
			53, 1, -6.08288, -3.59317, 6.83, 0, 0, 1,
			54, 1, -7.68286, -3.58619, 6.83, 0, 0, 1,
			54, 1, -7.68269, -3.54619, 6.83, 0, 0, 1,
			54, 1, -7.68286, -3.58619, 6.83, -0.00436158, -0.99999, -0,
			54, 0, -7.68286, -3.58619, 6.03, -0.00436158, -0.99999, -0,
			55, 0, -9.18285, -3.57965, 6.03, -0.00436158, -0.99999, -0,
			55, 1, -9.18285, -3.57965, 6.83, -0.00436158, -0.99999, -0,
			55, 0, -7.68269, -3.54619, 6.03, 0.00436158, 0.99999, -0,
			55, 1, -7.68269, -3.54619, 6.83, 0.00436158, 0.99999, -0,
			56, 1, -9.18267, -3.53965, 6.83, 0.00436158, 0.99999, -0,
			56, 0, -9.18267, -3.53965, 6.03, 0.00436158, 0.99999, -0,
			56, 1, -7.68269, -3.54619, 6.83, 0, 0, 1,
			56, 1, -7.68286, -3.58619, 6.83, 0, 0, 1,
			57, 1, -9.18285, -3.57965, 6.83, 0, 0, 1,
			57, 1, -9.18267, -3.53965, 6.83, 0, 0, 1,
			57, 1, -9.18285, -3.57965, 6.83, -0.00436158, -0.99999, -0,
			57, 0, -9.18285, -3.57965, 6.03, -0.00436158, -0.99999, -0,
			58, 0, -10.6828, -3.57311, 6.03, -0.00436158, -0.99999, -0,
			58, 1, -10.6828, -3.57311, 6.83, -0.00436158, -0.99999, -0,
			58, 0, -9.18267, -3.53965, 6.03, 0.00436158, 0.99999, -0,
			58, 1, -9.18267, -3.53965, 6.83, 0.00436158, 0.99999, -0,
			59, 1, -10.6827, -3.53311, 6.83, 0.00436158, 0.99999, -0,
			59, 0, -10.6827, -3.53311, 6.03, 0.00436158, 0.99999, -0,
			59, 1, -9.18267, -3.53965, 6.83, 0, 0, 1,
			59, 1, -9.18285, -3.57965, 6.83, 0, 0, 1,
			60, 1, -10.6828, -3.57311, 6.83, 0, 0, 1,
			60, 1, -10.6827, -3.53311, 6.83, 0, 0, 1,
			60, 1, -10.6828, -3.57311, 6.83, -0.00436158, -0.99999, -0,
			60, 0, -10.6828, -3.57311, 6.03, -0.00436158, -0.99999, -0,
			61, 0, -12.1828, -3.56656, 6.03, -0.00436158, -0.99999, -0,
			61, 1, -12.1828, -3.56656, 6.83, -0.00436158, -0.99999, -0,
			61, 0, -10.6827, -3.53311, 6.03, 0.00436158, 0.99999, -0,
			61, 1, -10.6827, -3.53311, 6.83, 0.00436158, 0.99999, -0,
			62, 1, -12.1826, -3.52656, 6.83, 0.00436158, 0.99999, -0,
			62, 0, -12.1826, -3.52656, 6.03, 0.00436158, 0.99999, -0,
			62, 1, -10.6827, -3.53311, 6.83, 0, 0, 1,
			62, 1, -10.6828, -3.57311, 6.83, 0, 0, 1,
			63, 1, -12.1828, -3.56656, 6.83, 0, 0, 1,
			63, 1, -12.1826, -3.52656, 6.83, 0, 0, 1,
			63, 1, -12.1828, -3.56656, 6.83, -0.00436158, -0.99999, -0,
			63, 0, -12.1828, -3.56656, 6.03, -0.00436158, -0.99999, -0,
			64, 0, -13.7828, -3.55959, 6.03, -0.00436158, -0.99999, -0,
			64, 1, -13.7828, -3.55959, 6.83, -0.00436158, -0.99999, -0,
			64, 0, -12.1826, -3.52656, 6.03, 0.00436158, 0.99999, -0,
			64, 1, -12.1826, -3.52656, 6.83, 0.00436158, 0.99999, -0,
			65, 1, -13.7826, -3.51959, 6.83, 0.00436158, 0.99999, -0,
			65, 0, -13.7826, -3.51959, 6.03, 0.00436158, 0.99999, -0,
			65, 1, -12.1826, -3.52656, 6.83, 0, 0, 1,
			65, 1, -12.1828, -3.56656, 6.83, 0, 0, 1,
			66, 1, -13.7828, -3.55959, 6.83, 0, 0, 1,
			66, 1, -13.7826, -3.51959, 6.83, 0, 0, 1,
			66, 1, -13.7828, -3.55959, 6.83, -0.00436158, -0.99999, -0,
			66, 0, -13.7828, -3.55959, 6.03, -0.00436158, -0.99999, -0,
			67, 0, -15.2828, -3.55304, 6.03, -0.00436158, -0.99999, -0,
			67, 1, -15.2828, -3.55304, 6.83, -0.00436158, -0.99999, -0,
			67, 0, -13.7826, -3.51959, 6.03, 0.00436158, 0.99999, -0,
			67, 1, -13.7826, -3.51959, 6.83, 0.00436158, 0.99999, -0,
			68, 1, -15.2826, -3.51304, 6.83, 0.00436158, 0.99999, -0,
			68, 0, -15.2826, -3.51304, 6.03, 0.00436158, 0.99999, -0,
			68, 1, -13.7826, -3.51959, 6.83, 0, 0, 1,
			68, 1, -13.7828, -3.55959, 6.83, 0, 0, 1,
			69, 1, -15.2828, -3.55304, 6.83, 0, 0, 1,
			69, 1, -15.2826, -3.51304, 6.83, 0, 0, 1,
			69, 1, -15.2828, -3.55304, 6.83, -0.00436158, -0.99999, -0,
			69, 0, -15.2828, -3.55304, 6.03, -0.00436158, -0.99999, -0,
			70, 0, -16.7828, -3.5465, 6.03, -0.00436158, -0.99999, -0,
			70, 1, -16.7828, -3.5465, 6.83, -0.00436158, -0.99999, -0,
			70, 0, -15.2826, -3.51304, 6.03, 0.00436158, 0.99999, -0,
			70, 1, -15.2826, -3.51304, 6.83, 0.00436158, 0.99999, -0,
			71, 1, -16.7826, -3.5065, 6.83, 0.00436158, 0.99999, -0,
			71, 0, -16.7826, -3.5065, 6.03, 0.00436158, 0.99999, -0,
			71, 1, -15.2826, -3.51304, 6.83, 0, 0, 1,
			71, 1, -15.2828, -3.55304, 6.83, 0, 0, 1,
			72, 1, -16.7828, -3.5465, 6.83, 0, 0, 1,
			72, 1, -16.7826, -3.5065, 6.83, 0, 0, 1,
			72, 1, -16.7828, -3.5465, 6.83, -0.00436158, -0.99999, -0,
			72, 0, -16.7828, -3.5465, 6.03, -0.00436158, -0.99999, -0,
			73, 0, -18.3828, -3.53952, 6.03, -0.00436158, -0.99999, -0,
			73, 1, -18.3828, -3.53952, 6.83, -0.00436158, -0.99999, -0,
			73, 0, -16.7826, -3.5065, 6.03, 0.00436158, 0.99999, -0,
			73, 1, -16.7826, -3.5065, 6.83, 0.00436158, 0.99999, -0,
			74, 1, -18.3826, -3.49952, 6.83, 0.00436158, 0.99999, -0,
			74, 0, -18.3826, -3.49952, 6.03, 0.00436158, 0.99999, -0,
			74, 1, -16.7826, -3.5065, 6.83, 0, 0, 1,
			74, 1, -16.7828, -3.5465, 6.83, 0, 0, 1,
			75, 1, -18.3828, -3.53952, 6.83, 0, 0, 1,
			75, 1, -18.3826, -3.49952, 6.83, 0, 0, 1,
			75, 1, -18.3828, -3.53952, 6.83, -0.00436158, -0.99999, -0,
			75, 0, -18.3828, -3.53952, 6.03, -0.00436158, -0.99999, -0,
			76, 0, -19.8827, -3.53298, 6.03, -0.00436158, -0.99999, -0,
			76, 1, -19.8827, -3.53298, 6.83, -0.00436158, -0.99999, -0,
			76, 0, -18.3826, -3.49952, 6.03, 0.00436158, 0.99999, -0,
			76, 1, -18.3826, -3.49952, 6.83, 0.00436158, 0.99999, -0,
			77, 1, -19.8826, -3.49298, 6.83, 0.00436158, 0.99999, -0,
			77, 0, -19.8826, -3.49298, 6.03, 0.00436158, 0.99999, -0,
			77, 1, -18.3826, -3.49952, 6.83, 0, 0, 1,
			77, 1, -18.3828, -3.53952, 6.83, 0, 0, 1,
			78, 1, -19.8827, -3.53298, 6.83, 0, 0, 1,
			78, 1, -19.8826, -3.49298, 6.83, 0, 0, 1,
			78, 1, -19.8827, -3.53298, 6.83, -0.00436158, -0.99999, -0,
			78, 0, -19.8827, -3.53298, 6.03, -0.00436158, -0.99999, -0,
			79, 0, -21.4827, -3.526, 6.03, -0.00436158, -0.99999, -0,
			79, 1, -21.4827, -3.526, 6.83, -0.00436158, -0.99999, -0,
			79, 0, -19.8826, -3.49298, 6.03, 0.00436158, 0.99999, -0,
			79, 1, -19.8826, -3.49298, 6.83, 0.00436158, 0.99999, -0,
			80, 1, -21.4826, -3.486, 6.83, 0.00436158, 0.99999, -0,
			80, 0, -21.4826, -3.486, 6.03, 0.00436158, 0.99999, -0,
			80, 1, -19.8826, -3.49298, 6.83, 0, 0, 1,
			80, 1, -19.8827, -3.53298, 6.83, 0, 0, 1,
			81, 1, -21.4827, -3.526, 6.83, 0, 0, 1,
			81, 1, -21.4826, -3.486, 6.83, 0, 0, 1,
			81, 1, -21.4827, -3.526, 6.83, -0.00436158, -0.99999, -0,
			81, 0, -21.4827, -3.526, 6.03, -0.00436158, -0.99999, -0,
			82, 0, -22.9827, -3.51946, 6.03, -0.00436158, -0.99999, -0,
			82, 1, -22.9827, -3.51946, 6.83, -0.00436158, -0.99999, -0,
			82, 0, -21.4826, -3.486, 6.03, 0.00436158, 0.99999, -0,
			82, 1, -21.4826, -3.486, 6.83, 0.00436158, 0.99999, -0,
			83, 1, -22.9825, -3.47946, 6.83, 0.00436158, 0.99999, -0,
			83, 0, -22.9825, -3.47946, 6.03, 0.00436158, 0.99999, -0,
			83, 1, -21.4826, -3.486, 6.83, 0, 0, 1,
			83, 1, -21.4827, -3.526, 6.83, 0, 0, 1,
			84, 1, -22.9827, -3.51946, 6.83, 0, 0, 1,
			84, 1, -22.9825, -3.47946, 6.83, 0, 0, 1,
			84, 1, -22.9827, -3.51946, 6.83, -0.00436158, -0.99999, -0,
			84, 0, -22.9827, -3.51946, 6.03, -0.00436158, -0.99999, -0,
			85, 0, -24.5827, -3.51248, 6.03, -0.00436158, -0.99999, -0,
			85, 1, -24.5827, -3.51248, 6.83, -0.00436158, -0.99999, -0,
			85, 0, -22.9825, -3.47946, 6.03, 0.00436158, 0.99999, -0,
			85, 1, -22.9825, -3.47946, 6.83, 0.00436158, 0.99999, -0,
			86, 1, -24.5825, -3.47248, 6.83, 0.00436158, 0.99999, -0,
			86, 0, -24.5825, -3.47248, 6.03, 0.00436158, 0.99999, -0,
			86, 1, -22.9825, -3.47946, 6.83, 0, 0, 1,
			86, 1, -22.9827, -3.51946, 6.83, 0, 0, 1,
			87, 1, -24.5827, -3.51248, 6.83, 0, 0, 1,
			87, 1, -24.5825, -3.47248, 6.83, 0, 0, 1,
			87, 1, -24.5827, -3.51248, 6.83, -0.00436158, -0.99999, -0,
			87, 0, -24.5827, -3.51248, 6.03, -0.00436158, -0.99999, -0,
			88, 0, -26.0827, -3.50594, 6.03, -0.00436158, -0.99999, -0,
			88, 1, -26.0827, -3.50594, 6.83, -0.00436158, -0.99999, -0,
			88, 0, -24.5825, -3.47248, 6.03, 0.00436158, 0.99999, -0,
			88, 1, -24.5825, -3.47248, 6.83, 0.00436158, 0.99999, -0,
			89, 1, -26.0825, -3.46594, 6.83, 0.00436158, 0.99999, -0,
			89, 0, -26.0825, -3.46594, 6.03, 0.00436158, 0.99999, -0,
			89, 1, -24.5825, -3.47248, 6.83, 0, 0, 1,
			89, 1, -24.5827, -3.51248, 6.83, 0, 0, 1,
			90, 1, -26.0827, -3.50594, 6.83, 0, 0, 1,
			90, 1, -26.0825, -3.46594, 6.83, 0, 0, 1,
			90, 1, -26.0827, -3.50594, 6.83, -0.00436158, -0.99999, -0,
			90, 0, -26.0827, -3.50594, 6.03, -0.00436158, -0.99999, -0,
			91, 0, -27.5827, -3.4994, 6.03, -0.00436158, -0.99999, -0,
			91, 1, -27.5827, -3.4994, 6.83, -0.00436158, -0.99999, -0,
			91, 0, -26.0825, -3.46594, 6.03, 0.00436158, 0.99999, -0,
			91, 1, -26.0825, -3.46594, 6.83, 0.00436158, 0.99999, -0,
			92, 1, -27.5825, -3.4594, 6.83, 0.00436158, 0.99999, -0,
			92, 0, -27.5825, -3.4594, 6.03, 0.00436158, 0.99999, -0,
			92, 1, -26.0825, -3.46594, 6.83, 0, 0, 1,
			92, 1, -26.0827, -3.50594, 6.83, 0, 0, 1,
			93, 1, -27.5827, -3.4994, 6.83, 0, 0, 1,
			93, 1, -27.5825, -3.4594, 6.83, 0, 0, 1 
		);
		TRI(
			  0,  1,  3,
			  1,  2,  3,
			  4,  5,  7,
			  5,  6,  7,
			  8,  9, 11,
			  9, 10, 11,
			 12, 13, 15,
			 13, 14, 15,
			 16, 17, 19,
			 17, 18, 19,
			 20, 21, 23,
			 21, 22, 23,
			 24, 25, 27,
			 25, 26, 27,
			 28, 29, 31,
			 29, 30, 31,
			 32, 33, 35,
			 33, 34, 35,
			 36, 37, 39,
			 37, 38, 39,
			 40, 41, 43,
			 41, 42, 43,
			 44, 45, 47,
			 45, 46, 47,
			 48, 49, 51,
			 49, 50, 51,
			 52, 53, 55,
			 53, 54, 55,
			 56, 57, 59,
			 57, 58, 59,
			 60, 61, 63,
			 61, 62, 63,
			 64, 65, 67,
			 65, 66, 67,
			 68, 69, 71,
			 69, 70, 71,
			 72, 73, 75,
			 73, 74, 75,
			 76, 77, 79,
			 77, 78, 79,
			 80, 81, 83,
			 81, 82, 83,
			 84, 85, 87,
			 85, 86, 87,
			 88, 89, 91,
			 89, 90, 91,
			 92, 93, 95,
			 93, 94, 95,
			 96, 97, 99,
			 97, 98, 99,
			100,101,103,
			101,102,103,
			104,105,107,
			105,106,107,
			108,109,111,
			109,110,111,
			112,113,115,
			113,114,115,
			116,117,119,
			117,118,119,
			120,121,123,
			121,122,123,
			124,125,127,
			125,126,127,
			128,129,131,
			129,130,131,
			132,133,135,
			133,134,135,
			136,137,139,
			137,138,139,
			140,141,143,
			141,142,143,
			144,145,147,
			145,146,147,
			148,149,151,
			149,150,151,
			152,153,155,
			153,154,155,
			156,157,159,
			157,158,159,
			160,161,163,
			161,162,163,
			164,165,167,
			165,166,167,
			168,169,171,
			169,170,171,
			172,173,175,
			173,174,175,
			176,177,179,
			177,178,179,
			180,181,183,
			181,182,183,
			184,185,187,
			185,186,187,
			188,189,191,
			189,190,191,
			192,193,195,
			193,194,195,
			196,197,199,
			197,198,199,
			200,201,203,
			201,202,203,
			204,205,207,
			205,206,207,
			208,209,211,
			209,210,211,
			212,213,215,
			213,214,215,
			216,217,219,
			217,218,219,
			220,221,223,
			221,222,223,
			224,225,227,
			225,226,227,
			228,229,231,
			229,230,231,
			232,233,235,
			233,234,235,
			236,237,239,
			237,238,239,
			240,241,243,
			241,242,243,
			244,245,247,
			245,246,247,
			248,249,251,
			249,250,251,
			252,253,255,
			253,254,255,
			256,257,259,
			257,258,259,
			260,261,263,
			261,262,263,
			264,265,267,
			265,266,267,
			268,269,271,
			269,270,271,
			272,273,275,
			273,274,275,
			276,277,279,
			277,278,279,
			280,281,283,
			281,282,283,
			284,285,287,
			285,286,287,
			288,289,291,
			289,290,291,
			292,293,295,
			293,294,295,
			296,297,299,
			297,298,299,
			300,301,303,
			301,302,303,
			304,305,307,
			305,306,307,
			308,309,311,
			309,310,311,
			312,313,315,
			313,314,315,
			316,317,319,
			317,318,319,
			320,321,323,
			321,322,323,
			324,325,327,
			325,326,327,
			328,329,331,
			329,330,331,
			332,333,335,
			333,334,335,
			336,337,339,
			337,338,339,
			340,341,343,
			341,342,343,
			344,345,347,
			345,346,347,
			348,349,351,
			349,350,351,
			352,353,355,
			353,354,355,
			356,357,359,
			357,358,359,
			360,361,363,
			361,362,363,
			364,365,367,
			365,366,367,
			368,369,371,
			369,370,371,
			372,373,375,
			373,374,375,
			376,377,379,
			377,378,379,
			380,381,383,
			381,382,383,
			384,385,387,
			385,386,387,
			388,389,391,
			389,390,391,
			392,393,395,
			393,394,395,
			396,397,399,
			397,398,399,
			400,401,403,
			401,402,403,
			404,405,407,
			405,406,407,
			408,409,411,
			409,410,411,
			412,413,415,
			413,414,415,
			416,417,419,
			417,418,419,
			420,421,423,
			421,422,423,
			424,425,427,
			425,426,427,
			428,429,431,
			429,430,431,
			432,433,435,
			433,434,435,
			436,437,439,
			437,438,439,
			440,441,443,
			441,442,443,
			444,445,447,
			445,446,447,
			448,449,451,
			449,450,451,
			452,453,455,
			453,454,455,
			456,457,459,
			457,458,459,
			460,461,463,
			461,462,463,
			464,465,467,
			465,466,467,
			468,469,471,
			469,470,471,
			472,473,475,
			473,474,475,
			476,477,479,
			477,478,479,
			480,481,483,
			481,482,483,
			484,485,487,
			485,486,487,
			488,489,491,
			489,490,491,
			492,493,495,
			493,494,495,
			496,497,499,
			497,498,499,
			500,501,503,
			501,502,503,
			504,505,507,
			505,506,507,
			508,509,511,
			509,510,511,
			512,513,515,
			513,514,515,
			516,517,519,
			517,518,519,
			520,521,523,
			521,522,523,
			524,525,527,
			525,526,527,
			528,529,531,
			529,530,531,
			532,533,535,
			533,534,535,
			536,537,539,
			537,538,539,
			540,541,543,
			541,542,543,
			544,545,547,
			545,546,547,
			548,549,551,
			549,550,551,
			552,553,555,
			553,554,555,
			556,557,559,
			557,558,559,
			560,561,563,
			561,562,563,
			564,565,567,
			565,566,567,
			568,569,571,
			569,570,571,
			572,573,575,
			573,574,575,
			576,577,579,
			577,578,579,
			580,581,583,
			581,582,583,
			584,585,587,
			585,586,587,
			588,589,591,
			589,590,591,
			592,593,595,
			593,594,595,
			596,597,599,
			597,598,599,
			600,601,603,
			601,602,603,
			604,605,607,
			605,606,607,
			608,609,611,
			609,610,611,
			612,613,615,
			613,614,615,
			616,617,619,
			617,618,619,
			620,621,623,
			621,622,623,
			624,625,627,
			625,626,627,
			628,629,631,
			629,630,631,
			632,633,635,
			633,634,635,
			636,637,639,
			637,638,639,
			640,641,643,
			641,642,643,
			644,645,647,
			645,646,647,
			648,649,651,
			649,650,651,
			652,653,655,
			653,654,655,
			656,657,659,
			657,658,659,
			660,661,663,
			661,662,663,
			664,665,667,
			665,666,667,
			668,669,671,
			669,670,671,
			672,673,675,
			673,674,675,
			676,677,679,
			677,678,679,
			680,681,683,
			681,682,683,
			684,685,687,
			685,686,687,
			688,689,691,
			689,690,691,
			692,693,695,
			693,694,695,
			696,697,699,
			697,698,699,
			700,701,703,
			701,702,703,
			704,705,707,
			705,706,707,
			708,709,711,
			709,710,711,
			712,713,715,
			713,714,715,
			716,717,719,
			717,718,719,
			720,721,723,
			721,722,723,
			724,725,727,
			725,726,727,
			728,729,731,
			729,730,731,
			732,733,735,
			733,734,735,
			736,737,739,
			737,738,739,
			740,741,743,
			741,742,743 
		);
	};
};
