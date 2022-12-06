<?xml version="1.0"?><doc>
<members>
<member name="M:webpage.#ctor" decl="true" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\webpage.h" line="21">
<summary>
constructor of webpage
</summary>
</member>
<member name="M:webpage.#ctor(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;,std.vector&lt;std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;,std.allocator&lt;std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignU" decl="true" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\webpage.h" line="26">
<summary>
parameterized constructor of webpage
</summary>
<param name="url">string of url</param>
<param name="keywords">vector of keywords</param>
<param name="impressions">impressions of webpage</param>
<param name="clickthr">click throughs of a webpage</param>
<param name="ctr">click through rate of a webpage</param>
<param name="rank">page rank</param>
<param name="score">score</param>
</member>
<member name="M:webpage.update_ctr" decl="true" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\webpage.h" line="40">
<summary>
updates click through rate
</summary>
</member>
<member name="M:webpage.update_score" decl="true" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\webpage.h" line="45">
<summary>
updates score
</summary>
</member>
<member name="M:webpage.update_ctr" decl="false" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\webpage.cpp" line="26">
<summary>
updates webpage's click through rate
</summary>
</member>
<member name="M:webpage.update_score" decl="false" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\webpage.cpp" line="34">
<summary>
updates webpage's score
</summary>
</member>
<member name="M:op_LeftShift(std.basic_ostream&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte}&gt;*!System.Runtime.CompilerServices.IsImplicitlyDereferenced,webpage!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="false" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\webpage.cpp" line="45">
<summary>
out stream operator overload
</summary>
<param name="os">out stream</param>
<param name="wp">webpage</param>
<returns></returns>
</member>
<member name="M:op_RightShift(std.basic_istream&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte}&gt;*!System.Runtime.CompilerServices.IsImplicitlyDereferenced,webpage*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="false" source="D:\academic\AUC\ALGO &amp; DSGN\VS proj\ALGO_DSGN_PROJ\webpage.cpp" line="62">
<summary>
in stream operator overload
</summary>
<param name="is">in stream</param>
<param name="wp">webpage</param>
<returns></returns>
</member>
</members>
</doc>