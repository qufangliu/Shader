varying vec4 v_fragmentColor;
varying vec2 v_texCoord;

uniform vec3 u_outlineColor;    //外发光颜色值
uniform float u_threshold;      //阈值
uniform float u_radius;         //半径

void main()
{
    float radius = u_radius;
    vec4 accum = vec4(0.0);     //累积颜色值，处理过后的颜色值
    vec4 normal = vec4(0.0);    //正常颜色值
    
    //正常颜色值
    normal = texture2D(CC_Texture0, vec2(v_texCoord.x, v_texCoord.y));
    
    //处理颜色值
    accum += texture2D(CC_Texture0, vec2(v_texCoord.x - radius, v_texCoord.y - radius));    //叠加左下角纹理颜色值
    accum += texture2D(CC_Texture0, vec2(v_texCoord.x + radius, v_texCoord.y - radius));    //叠加右下角纹理颜色值
    accum += texture2D(CC_Texture0, vec2(v_texCoord.x + radius, v_texCoord.y + radius));    //叠加右上角纹理颜色值
    accum += texture2D(CC_Texture0, vec2(v_texCoord.x - radius, v_texCoord.y + radius));    //叠加左上角纹理颜色值
    
    accum *= u_threshold;   //调节亮度
    accum.rgb = u_outlineColor * accum.a;   //外发光颜色值*叠加后的alpha  ？？？？
    accum.a = 1.0;
    
    normal = (accum * (1.0 - normal.a)) + (normal * normal.a);  //
    gl_FragColor = v_fragmentColor * normal;
}

