//顶点包含的属性
attribute vec4 a_position;  //顶点的position
attribute vec2 a_texCoord;  //纹理坐标
attribute vec4 a_color;     //顶点的颜色值


//传到fragment shader中的参数
#ifdef GL_ES
varying lowp vec4 v_fragmentColor;  //多个顶点的颜色值的插值变量
varying mediump vec2 v_texCoord;    //纹理坐标插值变量
#else
varying vec4 v_fragmentColor;
varying vec2 v_texCoord;
#endif

void main()
{
    gl_Position = CC_PMatrix * a_position;  //顶点坐标转换为gl坐标
    v_fragmentColor = a_color;              //直接输出顶点颜色值
    v_texCoord = a_texCoord;                //直接输出顶点纹理坐标值
}
