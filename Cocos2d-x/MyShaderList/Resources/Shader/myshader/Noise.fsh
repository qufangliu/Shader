#ifdef GL_ES
precision mediump float;            //使用中精度float

varying lowp vec4 v_fragmentColor;  //片元颜色值
varying mediump vec2 v_texCoord;    //片元对应的纹理坐标
#else
varying vec4 v_fragmentColor;
varying vec2 v_texCoord;
#endif

uniform float u_ratio;      //雪花点的比例

vec3 getNoiseColor()
{
//    //这样会随机闪烁
//    if (CC_Random01.x < u_ratio) {
//        return vec3(1.0, 1.0, 1.0);
//    }
//    else {
//        return texture2D(CC_Texture0, v_texCoord).xyz;
//    }
    
    //这样会随机闪烁不同叠加颜色后的纹理
    vec3 fragColor = texture2D(CC_Texture0, v_texCoord).xyz;
    fragColor.x *= CC_Random01.x;
    fragColor.y *= CC_Random01.y;
    fragColor.z *= CC_Random01.z;
    return fragColor;
    
    //划分晶格，然后进行线性插值计算？？？？？？？？
}

void main()
{
    gl_FragColor.xyz = getNoiseColor();
    gl_FragColor.w = 1.0;
    
//    gl_FragColor = texture2D(CC_Texture0, v_texCoord);  //使用纹理采样器获得纹理颜色值
}
