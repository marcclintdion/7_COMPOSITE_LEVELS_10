//Some global variables
var demoMaterial= new Object();
demoMaterial.gl= null;
demoMaterial.canvas= null;
demoMaterial.modelVertex = new Float32Array(
                                   [
                                    ]
                                   );
demoMaterial.modelVertexBuffer= null;
demoMaterial.modelWorldMatrix= null;
demoMaterial.viewMatrix= null;
demoMaterial.projectionMatrix= null;

demoMaterial.distributionEum            = {Beckmann:0, BlinnPhong:1, Num:2};
demoMaterial.geometryEum                = {Implicit:0, CookTorrance:1, Schlick:2, Walter:3, Num:4};
demoMaterial.diffuseEnergyConserveEum   = {None:0, FresnelDiff:1, Fresnel0:2, Num:3};

demoMaterial.fresnel_schlick=   "float fresnel(float f0, vec3 n, vec3 l){\n\
                                    return f0 + (1.0-f0) * pow(1.0- dot(n, l), 5.0);\n\
                                }\n";

demoMaterial.D_func= new Array(demoMaterial.distributionEum.Num);
demoMaterial.G_func= new Array(demoMaterial.geometryEum.Num);
demoMaterial.Diff_energyConverse= new Array(demoMaterial.diffuseEnergyConserveEum.Num);

demoMaterial.D_func[demoMaterial.distributionEum.Beckmann]=  "float distribution(vec3 n, vec3 h, float roughness){\n\
                                                                float m_Sq= roughness * roughness;\n\
                                                                float NdotH_Sq= max(dot(n, h), 0.0);\n\
                                                                NdotH_Sq= NdotH_Sq * NdotH_Sq;\n\
                                                                return exp( (NdotH_Sq - 1.0)/(m_Sq*NdotH_Sq) )/ (3.14159265 * m_Sq * NdotH_Sq * NdotH_Sq) ;\n\
                                                            }\n";

demoMaterial.D_func[demoMaterial.distributionEum.BlinnPhong]=  "float distribution(vec3 n, vec3 h, float roughness){\n\
                                                                    float m= 2.0/(roughness*roughness) - 2.0;\n\
                                                                    return (m+2.0) * pow( max(dot(n, h), 0.0), m) / (2.0 * 3.14159265);\n\
                                                                }\n";

demoMaterial.G_func[demoMaterial.geometryEum.Implicit]=      "float geometry(vec3 n, vec3 h, vec3 v, vec3 l, float roughness){\n\
                                                                return max(dot(n, l), 0.0) * max(dot(n, v), 0.0);\n\
                                                            }\n";

demoMaterial.G_func[demoMaterial.geometryEum.CookTorrance]=  "float geometry(vec3 n, vec3 h, vec3 v, vec3 l, float roughness){\n\
                                                                float NdotH= dot(n, h);\n\
                                                                float NdotL= dot(n, l);\n\
                                                                float NdotV= dot(n, v);\n\
                                                                float VdotH= dot(v, h);\n\
                                                                float NdotL_clamped= max(NdotL, 0.0);\n\
                                                                float NdotV_clamped= max(NdotV, 0.0);\n\
                                                                return min( min( 2.0 * NdotH * NdotV_clamped / VdotH, 2.0 * NdotH * NdotL_clamped / VdotH), 1.0);\n\
                                                            }\n";

demoMaterial.G_func[demoMaterial.geometryEum.Schlick]=       "float geometry(vec3 n, vec3 h, vec3 v, vec3 l, float roughness){\n\
                                                                float NdotL_clamped= max(dot(n, l), 0.0);\n\
                                                                float NdotV_clamped= max(dot(n, v), 0.0);\n\
                                                                float k= roughness * sqrt(2.0/3.14159265);\n\
                                                                float one_minus_k= 1.0 -k;\n\
                                                                return ( NdotL_clamped / (NdotL_clamped * one_minus_k + k) ) * ( NdotV_clamped / (NdotV_clamped * one_minus_k + k) );\n\
                                                            }\n";

demoMaterial.G_func[demoMaterial.geometryEum.Walter]=      "float geometry(vec3 n, vec3 h, vec3 v, vec3 l, float roughness){\n\
                                                                float NdotV= dot(n, v);\n\
                                                                float NdotL= dot(n, l);\n\
                                                                float HdotV= dot(h, v);\n\
                                                                float HdotL= dot(h, l);\n\
                                                                float NdotV_clamped= max(NdotV, 0.0);\n\
                                                                float a= 1.0/ ( roughness * tan( acos(NdotV_clamped) ) );\n\
                                                                float a_Sq= a* a;\n\
                                                                float a_term;\n\
                                                                if (a<1.6)\n\
                                                                    a_term= (3.535 * a + 2.181 * a_Sq)/(1.0 + 2.276 * a + 2.577 * a_Sq);\n\
                                                                else\n\
                                                                    a_term= 1.0;\n\
                                                                return  ( step(0.0, HdotL/NdotL) * a_term  ) * \n\
                                                                        ( step(0.0, HdotV/NdotV) * a_term  ) ;\n\
                                                            }\n";

demoMaterial.Diff_energyConverse[demoMaterial.diffuseEnergyConserveEum.None] = "float diffuseEnergyRatio(float f0, vec3 n, vec3 l){\n\
                                                                                    return 1.0;\n\
                                                                                }\n";

demoMaterial.Diff_energyConverse[demoMaterial.diffuseEnergyConserveEum.FresnelDiff] =  "float diffuseEnergyRatio(float f0, vec3 n, vec3 l){\n\
                                                                                            return 1.0 - fresnel(f0, n, l);\n\
                                                                                        }\n";

demoMaterial.Diff_energyConverse[demoMaterial.diffuseEnergyConserveEum.Fresnel0] = "float diffuseEnergyRatio(float f0, vec3 n, vec3 l){\n\
                                                                                        return 1.0 - f0;\n\
                                                                                    }\n";



demoMaterial.shaderMicrofacetVS="attribute vec3  a_position;\n\
                                attribute vec3  a_normal;\n\
                                varying vec3    v_position;\n\
                                varying vec3    v_normal;\n\
                                uniform mat4	u_worldViewMat;\n\
                                uniform mat4	u_projMat;\n\
                                void main() {\n\
                                    v_normal= (u_worldViewMat * vec4(a_normal.x, a_normal.y, a_normal.z, 0.0)).xyz;\n\
                                    vec4 pos= u_worldViewMat * vec4(a_position.x, a_position.y, a_position.z, 1.0);\n\
                                    v_position= pos.xyz;\n\
                                    gl_Position = u_projMat * pos;\n\
                                }\n";

demoMaterial.shaderMicrofacetFS_declaration="precision highp float;\n\
                                            varying vec3    v_position;\n\
                                            varying vec3    v_normal;\n\
                                            uniform float	u_fresnel0;\n\
                                            uniform float	u_roughness;\n\
                                            uniform vec3	u_diffuseColor;\n\
                                            uniform vec3	u_lightColor;\n\
                                            uniform vec3	u_lightDir;     // in view space  \n";

demoMaterial.shaderMicrofacetFS_main=       "void main() {\n\
                                                vec3 normal =  normalize(v_normal);\n\
                                                vec3 view   = -normalize(v_position);\n\
                                                vec3 halfVec=  normalize(u_lightDir + view);\n\
                                                float NdotL= dot(normal, u_lightDir);\n\
                                                float NdotV= dot(normal, view);\n\
                                                float NdotL_clamped= max(NdotL, 0.0);\n\
                                                float NdotV_clamped= max(NdotV, 0.0);\n\
                                                float brdf_spec= fresnel(u_fresnel0, halfVec, u_lightDir) * geometry(normal, halfVec, view, u_lightDir, u_roughness) * distribution(normal, halfVec, u_roughness) / (4.0 * NdotL_clamped * NdotV_clamped);\n\
                                                vec3 color_spec= NdotL_clamped * brdf_spec * u_lightColor;\n\
                                                vec3 color_diff= NdotL_clamped * diffuseEnergyRatio(u_fresnel0, normal, u_lightDir) * u_diffuseColor * u_lightColor;\n\
                                                gl_FragColor = vec4( color_diff + color_spec, 1.0)  ;\n\
                                            }\n";


demoMaterial.microfacetShaderProgram= new Array(demoMaterial.distributionEum.Num);
for ( i= 0; i<demoMaterial.distributionEum.Num; ++i){
    demoMaterial.microfacetShaderProgram[i]= new Array(demoMaterial.geometryEum.Num);
    for ( j= 0; j<demoMaterial.geometryEum.Num; ++j){
        demoMaterial.microfacetShaderProgram[i][j]= new Array(demoMaterial.diffuseEnergyConserveEum.Num);
    }
}

demoMaterial.timer= new Object();
demoMaterial.timer.lastTime= (new Date()).getTime() * 0.001;
demoMaterial.timer.elapsedTime = 0.0;
demoMaterial.timer.totalTime = 0.0;
demoMaterial.timer.update = function() {
    var now = (new Date()).getTime() * 0.001;
    this.elapsedTime = now - this.lastTime;
    this.lastTime = now;
    if (this.elapsedTime > 0.05)
        this.elapsedTime = 0.05; // clamp the time to avoid unstable simulation...
    this.totalTime += this.elapsedTime;
}

demoMaterial.camPosOffset= Vector3(0.0, 0.0, 23.0);
demoMaterial.camLookAt= Vector3(0.0, 0.0, 0.0);
demoMaterial.camRotatePhi= 50.0;    // in degree
demoMaterial.camRotateTheta= -5.0;   // in degree

var INF_VAL= 999999.9;

demoMaterial.input= new Object();
demoMaterial.input.isDragging= false;
demoMaterial.input.isMoved= false;
demoMaterial.input.isJustReleased= false;
demoMaterial.input.mouseDownPos= new Object();
demoMaterial.input.mouseDownPos.x= INF_VAL;
demoMaterial.input.mouseDownPos.y= INF_VAL;

demoMaterial.input.mouseCurrentPos= new Object();
demoMaterial.input.mouseCurrentPos.x= INF_VAL;
demoMaterial.input.mouseCurrentPos.y= INF_VAL;

demoMaterial.input.mouseLastPos= new Object();
demoMaterial.input.mouseLastPos.x= INF_VAL;
demoMaterial.input.mouseLastPos.y= INF_VAL;

demoMaterial.lightColor= Vector3(1.0 * Math.PI, 1.0 * Math.PI, 1.0 * Math.PI);       // multipy with PI because from the definition of the punctual light source
demoMaterial.lightDir= Vector3(1.0, 1.0, 1.0);
demoMaterial.lightDir.normalize();
demoMaterial.refractiveIndex= 1.5;
demoMaterial.roughness= 0.1;
demoMaterial.diffuseColor= Vector3(0.9 / Math.PI, 0.5 / Math.PI, 0.55 / Math.PI);

/**
 * The main entry point
 */
function demoMmaterial_main() {
	//
	demoMaterial.canvas = document.getElementById("canvasMaterial");
	demoMaterial.gl = WebGLUtils.setupWebGL(demoMaterial.canvas);
	//Couldn't setup GL
	if(!demoMaterial.gl) {
		//alert("No WebGL!");
		return;
	}
    
    document.getElementById("material_refractiveIndex").value= demoMaterial.refractiveIndex;
    document.getElementById("material_roughness").value= demoMaterial.roughness;
	demoMaterial.projectionMatrix= createPerspectiveProjectionMatrix(degreeToRadian(45.0), demoMaterial.canvas.width/demoMaterial.canvas.height, 0.1, 100.0);
    demoMaterial.modelWorldMatrix= createRotationYMatrix(degreeToRadian(demoMaterial.camRotatePhi));
    demoMaterial.modelWorldMatrix[13]= -5.0;
    demoMaterial.viewMatrix= createLookAtMatrix( 
        matrixMultiplyVector3(createRotationYMatrix(degreeToRadian(demoMaterial.camRotatePhi)), matrixMultiplyVector3(createRotationXMatrix(degreeToRadian(demoMaterial.camRotateTheta)), demoMaterial.camPosOffset) )
        , demoMaterial.camLookAt, Vector3(0.0, 1.0, 0.0) );
    
	//
	if(!demoMaterial.init()) {
		//alert("Could not init!");
		return;
	}

	//
	demoMaterial.update();
}

function demoMmaterial_update() {
	demoMaterial.update();
}

/**
 * Init our shaders, buffers and any additional setup
 */
demoMaterial.init= function() {
	//
	if(!this.initShaders()) {
		//alert("Could not init shaders!");
		return false;
	}

	//
	if(!this.initBuffers()) {
		//alert("Could not init buffers!");
		return false;
	}

	//
	if(!this.initTextures()) {
		//alert("Could not init textures!");
		return false;
	}

	//
	this.gl.clearColor(0.4, 0.4, 0.4, 1.0);
	this.gl.viewport(0, 0, this.canvas.width, this.canvas.height);
	this.gl.clearDepth(1.0);
    this.gl.enable(this.gl.DEPTH_TEST);
    this.gl.disable(this.gl.CULL_FACE);


	this.canvas.onmousedown= function(ev){
		demoMaterial.input.mouseDownPos.x= ev.clientX;
		demoMaterial.input.mouseDownPos.y= ev.clientY;
		demoMaterial.canvas.onmousemove(ev);
		demoMaterial.input.isDragging= true;
	}
	
	this.canvas.onmouseup= function(ev){
		demoMaterial.input.mouseDownPos.x= INF_VAL;
		demoMaterial.input.mouseDownPos.y= INF_VAL;
		demoMaterial.canvas.onmousemove(ev);
		demoMaterial.input.isDragging= false;
		demoMaterial.input.isJustReleased= true;
	}
	
	this.canvas.onmousemove= function(ev){
		demoMaterial.input.mouseLastPos.x= demoMaterial.input.mouseLastPos.x== INF_VAL ? ev.clientX : demoMaterial.input.mouseCurrentPos.x;
		demoMaterial.input.mouseLastPos.y= demoMaterial.input.mouseLastPos.y== INF_VAL ? ev.clientY : demoMaterial.input.mouseCurrentPos.y;
		demoMaterial.input.mouseCurrentPos.x= ev.clientX;
		demoMaterial.input.mouseCurrentPos.y= ev.clientY;
		demoMaterial.input.isMoved= true;
	}

	this.canvas.onmouseout= function(ev){
		if (demoMaterial.input.isDragging){
			demoMaterial.canvas.onmouseup(ev);
			demoMaterial.input.isMoved= false;
		}
	}

	return true;
}

/**
 * Init our shaders, load them, create the program and attach them
 */
demoMaterial.initShaders= function() {
    
    
    for (i= 0; i<this.distributionEum.Num; ++i){
        for (j= 0; j<this.geometryEum.Num; ++j){
            for (k= 0; k<this.diffuseEnergyConserveEum.Num; ++k){
                var createdShaderProgram= this.gl.createProgram();
                if(createdShaderProgram == null) {
                    alert("No Shader Program!");
                    return;
                }
                this.microfacetShaderProgram[i][j][k]= createdShaderProgram;
                
                // compile shader
                var microfacetVertexShader = this.createShader(this.gl.VERTEX_SHADER, this.shaderMicrofacetVS);
                var microfacetFragmentShaderString= this.shaderMicrofacetFS_declaration + this.fresnel_schlick + this.D_func[i] + this.G_func[j] + this.Diff_energyConverse[k] + this.shaderMicrofacetFS_main;
                var microfacetFragmentShader = this.createShader(this.gl.FRAGMENT_SHADER, microfacetFragmentShaderString);
                
                this.gl.attachShader(createdShaderProgram, microfacetVertexShader);
                this.gl.attachShader(createdShaderProgram, microfacetFragmentShader);
                this.gl.linkProgram(createdShaderProgram);	
                
                if(!this.gl.getProgramParameter(createdShaderProgram, this.gl.LINK_STATUS)) {
                    alert("Could not link shader!");
                    this.gl.deleteProgram(createdShaderProgram);
                    return false;
                }
                
                this.gl.useProgram(this.shaderProgram);
                
                // get constant location
                createdShaderProgram.a_position = this.gl.getAttribLocation(createdShaderProgram, "a_position");
                createdShaderProgram.a_normal = this.gl.getAttribLocation(createdShaderProgram, "a_normal");
                this.gl.enableVertexAttribArray(createdShaderProgram.a_position);
                this.gl.enableVertexAttribArray(createdShaderProgram.a_normal);
                
                createdShaderProgram.u_lightDir= this.gl.getUniformLocation(createdShaderProgram, "u_lightDir");
                createdShaderProgram.u_lightColor= this.gl.getUniformLocation(createdShaderProgram, "u_lightColor");
                createdShaderProgram.u_diffuseColor= this.gl.getUniformLocation(createdShaderProgram, "u_diffuseColor");
                createdShaderProgram.u_roughness= this.gl.getUniformLocation(createdShaderProgram, "u_roughness");
                createdShaderProgram.u_fresnel0= this.gl.getUniformLocation(createdShaderProgram, "u_fresnel0");
                createdShaderProgram.u_projMat= this.gl.getUniformLocation(createdShaderProgram, "u_projMat");
                createdShaderProgram.u_worldViewMat= this.gl.getUniformLocation(createdShaderProgram, "u_worldViewMat");
            }
        }
    }
    
    
	return true;
}

/**
 *
 */
demoMaterial.createShader = function(shaderType, shaderSource) {
	//Create a shader
	var shader = this.gl.createShader(shaderType);
	//
	if(shader == null) {
		alert("Could not create shader!");
		return null;
	}

	//
	this.gl.shaderSource(shader, shaderSource);
	this.gl.compileShader(shader);

	//
	if(!this.gl.getShaderParameter(shader, this.gl.COMPILE_STATUS)) {
		alert("Could not compile shader!" + this.gl.getShaderInfoLog(shader) );
		this.gl.deleteShader(shader);
		return null;
	}

	//
	return shader;
}

/**
 * Init our required buffers (in our case for our triangle)
 */
demoMaterial.initBuffers= function() {
	//
	this.modelVertexBuffer = this.gl.createBuffer();
	this.gl.bindBuffer(this.gl.ARRAY_BUFFER, this.modelVertexBuffer);
	this.gl.bufferData(this.gl.ARRAY_BUFFER, this.modelVertex, this.gl.STATIC_DRAW);

	this.gl.bindBuffer(this.gl.ARRAY_BUFFER, null);
	return true;
}

/**
 * Init textures for icons
 */
demoMaterial.initTextures = function() {
	return true;
}

/**
 * Update loop
 */
demoMaterial.update= function(){

	this.timer.update();

    if ( document.getElementById('material_isModelRotated').checked )
        this.modelWorldMatrix= matrixMultiplyMatrix(this.modelWorldMatrix, createRotationYMatrix( degreeToRadian(-15.0) * this.timer.elapsedTime) ) ;
    
	if (this.input.isDragging){
		// dragging
		var mouseDeltaX= this.input.mouseCurrentPos.x - this.input.mouseLastPos.x;
		var mouseDeltaY= this.input.mouseCurrentPos.y - this.input.mouseLastPos.y;
        
        this.camRotatePhi+= -mouseDeltaX;
        this.camRotateTheta+= -mouseDeltaY;
        if (this.camRotateTheta >= 89.0)
            this.camRotateTheta = 89.0;
        else if (this.camRotateTheta <= -89.0)
            this.camRotateTheta = -89.0;
	}
    
    this.viewMatrix= createLookAtMatrix( 
        matrixMultiplyVector3(createRotationYMatrix(degreeToRadian(this.camRotatePhi)), matrixMultiplyVector3(createRotationXMatrix(degreeToRadian(this.camRotateTheta)), this.camPosOffset) )
        , this.camLookAt, Vector3(0.0, 1.0, 0.0) );
    
	this.draw();

	// update input
	if (this.input.isMoved){
		this.input.mouseLastPos.x= this.input.mouseCurrentPos.x;
		this.input.mouseLastPos.y= this.input.mouseCurrentPos.y;
		this.input.isMoved= false;
	}
	if (this.input.isJustReleased)
		this.input.isJustReleased= false;
	window.requestAnimFrame(demoMmaterial_update, this.canvas);
}

/**
 * Our draw/render method
 */
demoMaterial.draw= function() {	
	//
	this.gl.clear(this.gl.COLOR_BUFFER_BIT | this.gl.DEPTH_BUFFER_BIT);

	// draw model
    var currentD_func= 0;
    var currentG_func= 0;
    var currentDiffEnenergyConverse= 0;
    if(document.getElementById('material_D_func_beckmann').checked)
        currentD_func= demoMaterial.distributionEum.Beckmann;
    else if(document.getElementById('material_D_func_blinnPhong').checked)
        currentD_func= demoMaterial.distributionEum.BlinnPhong;
    
    if(document.getElementById('material_G_func_Implicit').checked)
        currentG_func= demoMaterial.geometryEum.Implicit;
    else if(document.getElementById('material_G_func_CookTorrance').checked)
        currentG_func= demoMaterial.geometryEum.CookTorrance;
    else if(document.getElementById('material_G_func_Schlick').checked)
        currentG_func= demoMaterial.geometryEum.Schlick;
    else if(document.getElementById('material_G_func_Walter').checked)
        currentG_func= demoMaterial.geometryEum.Walter;
    
    if(document.getElementById('material_diffuseEnergyConserved_None').checked)
        currentDiffEnenergyConverse= demoMaterial.diffuseEnergyConserveEum.None;
    else if(document.getElementById('material_diffuseEnergyConserved_FresnelDiff').checked)
        currentDiffEnenergyConverse= demoMaterial.diffuseEnergyConserveEum.FresnelDiff;
    else if(document.getElementById('material_diffuseEnergyConserved_Fresnel0').checked)
        currentDiffEnenergyConverse= demoMaterial.diffuseEnergyConserveEum.Fresnel0;
    
    var currentShaderProgram= this.microfacetShaderProgram[currentD_func][currentG_func][currentDiffEnenergyConverse];
    
    this.refractiveIndex= parseFloat(document.getElementById("material_refractiveIndex").value);
    this.roughness= parseFloat(document.getElementById("material_roughness").value);    
    
    
	this.gl.useProgram(currentShaderProgram);
	this.gl.bindBuffer(this.gl.ARRAY_BUFFER, this.modelVertexBuffer);
	this.gl.enableVertexAttribArray(currentShaderProgram.a_position);
	this.gl.enableVertexAttribArray(currentShaderProgram.a_normal);
	this.gl.vertexAttribPointer(currentShaderProgram.a_position, 3, this.gl.FLOAT, false, 4*6, 0);
	this.gl.vertexAttribPointer(currentShaderProgram.a_normal, 3, this.gl.FLOAT, false, 4*6, 4*3);
    
    
    var worldView= matrixMultiplyMatrix(this.viewMatrix, this.modelWorldMatrix);
    var viewSpaceLightDir= matrixMultiplyVector4(this.viewMatrix, Vector4(this.lightDir.x, this.lightDir.y, this.lightDir.z, 0) );
    var fresnel0= (1.0 - this.refractiveIndex)/(1.0 + this.refractiveIndex);
    fresnel0= fresnel0 * fresnel0;
    var diffColor= document.getElementById('material_isRenderDiffuse').checked ?
                        demoMaterial.diffuseColor:
                        Vector3(0.0, 0.0, 0.0);
    
    document.getElementById("material_fresnel").value= (""+fresnel0).substring(0, 5);
    document.getElementById("material_refractiveIndex_Label").value= (""+this.refractiveIndex).substring(0, 5);
    document.getElementById("material_roughness_Label").value= (""+this.roughness).substring(0, 5);
    
    
    this.gl.uniformMatrix4fv(currentShaderProgram.u_projMat, false, this.projectionMatrix);
    this.gl.uniformMatrix4fv(currentShaderProgram.u_worldViewMat, false, worldView);
    this.gl.uniform3f(currentShaderProgram.u_lightDir, viewSpaceLightDir.x, viewSpaceLightDir.y, viewSpaceLightDir.z);
    this.gl.uniform3f(currentShaderProgram.u_lightColor, this.lightColor.x, this.lightColor.y, this.lightColor.z);
    this.gl.uniform3f(currentShaderProgram.u_diffuseColor, diffColor.x, diffColor.y, diffColor.z);
    this.gl.uniform1f(currentShaderProgram.u_roughness, this.roughness);
    this.gl.uniform1f(currentShaderProgram.u_fresnel0, fresnel0);    
    
    
    this.gl.drawArrays(this.gl.TRIANGLES, 0, this.modelVertex.length/(3+3) );

}