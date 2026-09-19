cmake_minimum_required(VERSION 4.0)
project(Clion C)

set(CMAKE_C_STANDARD 99)

add_executable(Clion
        Chapter2/two_func.c
        Chapter2/nogood.c
        Chapter2/homework.c
        Chapter3/platinum.c
        Chapter3/print1.c
        Chapter3/bases.c
        Chapter3/toobig.c
        Chapter3/print2.c
        Chapter3/charcode.c
        Chapter3/altnames.c
        Chapter3/showf_pt.c
        Chapter3/floaterr.c
        Chapter3/typesize.c
        Chapter3/badcount.c
        Chapter3/escape.c
        "C Primer Plus/Chapter4/talkback.c"
        Chapter3/homework.c
        Chapter3/homework3_11_1.c
        Chapter3/homework3_11_2.c
        Chapter3/homework3_11_3.c
        Chapter3/homework3_11_4.c
        Chapter3/homework3_11_5.c
        Chapter3/homework3_11_6.c
        Chapter3/homework3_11_7.c
        Chapter3/homework3_11_8.c
        "C Primer Plus/Chapter4/prasie1.c"
        "C Primer Plus/Chapter4/praise2.c"
        "C Primer Plus/Chapter4/pizza.c"
        "C Primer Plus/Chapter4/defines.c"
        "C Primer Plus/Chapter4/printout.c"
        "C Primer Plus/Chapter4/width.c"
        "C Primer Plus/Chapter4/floats.c"
        "C Primer Plus/Chapter4/flags.c"
        "C Primer Plus/Chapter4/stringf.c"
        "C Primer Plus/Chapter4/intconv.c"
        "C Primer Plus/Chapter4/floatcnv.c"
        "C Primer Plus/Chapter4/prntval.c"
        "C Primer Plus/Chapter4/longstrg.c"
        "C Primer Plus/Chapter4/input.c"
        "C Primer Plus/Chapter4/varwid.c"
        "C Primer Plus/Chapter4/skiptwo.c"
        "C Primer Plus/Chapter4/homework02.c"
        "C Primer Plus/Chapter4/homework04.c"
        C_Project/2.11.c
        chapter0/2.11.c
        "C Primer Plus/Chapter4/homework05.c"
        "C Primer Plus/Chapter4/homework06.c"
        "C Primer Plus/Chapter4/homework07.c"
        "C Primer Plus/Chapter4/homework08.c"
        "C Primer Plus/Chapter4/homework09.c"
        "C Primer Plus/Chapter4/homework011.c"
        "C Primer Plus/Chapter4/homework1.c"
        "C Primer Plus/Chapter4/homework2.c"
        "C Primer Plus/Chapter4/homework3.c"
        "C Primer Plus/Chapter4/homework4.c"
        "C Primer Plus/Chapter4/homework5.c"
        "C Primer Plus/Chapter4/homework6.c"
        "C Primer Plus/Chapter4/homework7.c"
        "C Primer Plus/Chapter4/homework8.c"
        "C Primer Plus/Chapter4/Chapter5/11.c"
        "C Primer Plus/Chapter5/shoes1.c"
        "C Primer Plus/Chapter5/shoes2.c"
        "C Primer Plus/Chapter5/golf.c"
        "C Primer Plus/Chapter5/squares.c"
        "C Primer Plus/Chapter5/wheat.c"
        "C Primer Plus/Chapter5/divide.c"
        "C Primer Plus/Chapter5/rules.c"
        "C Primer Plus/Chapter5/sizeof.c"
        "C Primer Plus/Chapter5/min_sec.c"
        "C Primer Plus/Chapter5/add_one.c"
        "C Primer Plus/Chapter5/post_pre.c"
        "C Primer Plus/Chapter5/bottles.c"
        "C Primer Plus/Chapter5/addemup.c"
        "C Primer Plus/Chapter5/convert.c"
        "C Primer Plus/Chapter5/pound.c"
        "C Primer Plus/Chapter5/running.c"
        "C Primer Plus/Chapter5/homework01.c"
        "C Primer Plus/Chapter5/homework04.c"
        "C Primer Plus/Chapter5/homework05.c"
        "C Primer Plus/Chapter5/homework06.c"
        "C Primer Plus/Chapter5/homework07.c"
        "C Primer Plus/Chapter5/homework08.c"
        "C Primer Plus/Chapter5/homework10.c"
        "C Primer Plus/Chapter5/homework11.c"
        "C Primer Plus/Chapter5/homework012.c"
        "C Primer Plus/Chapter5/homework1.c"
        "C Primer Plus/Chapter5/homework2.c"
        "C Primer Plus/Chapter5/homework3.c"
        "C Primer Plus/Chapter5/homework4.c"
        "C Primer Plus/Chapter5/homework5.c"
        "C Primer Plus/Chapter5/homework6.c"
        "C Primer Plus/Chapter5/homework7.c"
        "C Primer Plus/Chapter5/homework8.c"
        "C Primer Plus/Chapter5/homework9.c"
        Chapter6/summing.c
        Chapter6/when.c
        Chapter6/while1.c
        "Chapter6/while 2.c"
        Chapter6/cmplt.c
        Chapter6/t_and_f.c
        Chapter6/truth.c
        Chapter6/trouble.c
        Chapter6/boolean.c
        Chapter6/10sweetie1.c
        Chapter6/11sweetie2.c
        Chapter6/12for_cube.c
        Chapter6/for_show.c
        Chapter6/13postage.c
        Chapter6/14zeno.c
        Chapter6/15do_while.c
        Chapter6/16entry.c
        Chapter6/17rows1.c
        Chapter6/18rows2.c
        Chapter6/19scores_in.c
        Chapter6/20power.c
        Chapter6/homework1.c
        Chapter6/homework2.c
        Chapter6/homework3.c
        Chapter6/homework4.c
        Chapter6/homework5.c
        Chapter6/homework6.c
        Chapter6/homework7.c
        Chapter6/homewort7_2.c
        Chapter6/homework8_a.c
        Chapter6/homework8_b.c
        Chapter6/homework8_c.c
        Chapter6/homework8_d.c
        Chapter6/homework9.c
        Chapter6/homework11.c
        Chapter6/homework14.c
        Chapter6/homework01.c
        Chapter6/homework02.c
        Chapter6/homework03.c
        Chapter6/homework04.c
        Chapter6/homework05.c
        Chapter6/homework06.c
        Chapter6/homework07.c
        Chapter6/homework08.c
        Chapter6/homework09.c
        Chapter6/homework010.c
        Chapter6/homework011.c
        Chapter6/homework012.c
        Chapter6/homework013.c
        Chapter6/homework014.c
        Chapter6/homework015.c
        Chapter6/homework016.c
        Chapter6/homework017.c
        Chapter6/homework018.c
        "C Primer Plus/Chapter7/1colddays.c"
        "C Primer Plus/Chapter7/2cypher1.c"
        "C Primer Plus/Chapter7/3cypher2.c"
        "C Primer Plus/Chapter7/4electric.c"
        "C Primer Plus/Chapter7/5divisors1.c"
        "C Primer Plus/Chapter7/5divisors2.c"
        "C Primer Plus/Chapter7/6chount.c"
        "C Primer Plus/Chapter7/7wordcnt.c"
        "C Primer Plus/Chapter7/8paint.c"
        "C Primer Plus/Chapter7/9skippart.c"
        "C Primer Plus/Chapter7/10break.c"
        "C Primer Plus/Chapter7/11animals.c"
        "C Primer Plus/Chapter7/12vowels.c"
        "C Primer Plus/Chapter7/homework1.c"
        "C Primer Plus/Chapter7/homework5.c"
        "C Primer Plus/Chapter7/homework6.c"
        "C Primer Plus/Chapter7/homework7.c"
        "C Primer Plus/Chapter7/homework8.c"
        "C Primer Plus/Chapter7/homework9.c"
        "C Primer Plus/Chapter7/homework10.c"
        "C Primer Plus/Chapter7/homework01.c"
        "C Primer Plus/Chapter7/homework02.c"
        "C Primer Plus/Chapter7/homework03.c"
        "C Primer Plus/Chapter7/homework04.c"
        "C Primer Plus/Chapter7/homework05.c"
        "C Primer Plus/Chapter7/homework06.c"
        "C Primer Plus/Chapter7/homework07.c"
        "C Primer Plus/Chapter7/homework08.c"
        "C Primer Plus/Chapter7/homework09.c"
        "C Primer Plus/Chapter7/homework010.c"
        "C Primer Plus/Chapter7/homework011.c"
        Chapter8/1echo.c
        Chapter8/2echo_eof.c
        Chapter8/file_eof.c
        Chapter8/4guess.c
        Chapter8/5showchar1.c
        Chapter8/6showchar2.c
        Chapter8/7checking.c
        Chapter8/8menuette.c
        Chapter8/10.1homework.c
        Chapter8/10.2homework.c
        Chapter8/10_3homework.c
        Chapter8/10_6homework.c
        Chapter8/11_1homework.c
        Chapter8/11_2homework.c
        Chapter8/11_3homework.c
        Chapter8/11_4homework.c
        Chapter8/11_5homework.c
        Chapter8/11_6homework.c
        Chapter8/11_7homework.c
        Chapter8/11_8homework.c
        "C Primer Plus/Chapter9/1lethead1.c"
        "C Primer Plus/Chapter9/1lethead1.c"
        "C Primer Plus/Chapter9/2lethead2.c"
        "C Primer Plus/Chapter9/3lesser.c"
        "C Primer Plus/Chapter9/4misuse.c"
        "C Primer Plus/Chapter9/5proto.c"
        "C Primer Plus/Chapter9/6recur.c"
        "C Primer Plus/Chapter9/7factor.c"
        "C Primer Plus/Chapter9/8binary.c"
        "C Primer Plus/Chapter9/9hotel/9usehotel.c"
        "C Primer Plus/Chapter9/9hotel/10hotel.c"
        "C Primer Plus/Chapter9/9hotel/11hotel.h"
        "C Primer Plus/Chapter9/12loccheck.c"
        "C Primer Plus/Chapter9/13swap1.c"
        "C Primer Plus/Chapter9/14swap2.c"
        "C Primer Plus/Chapter9/15swap3.c"
        "C Primer Plus/Chapter9/10_2homework.c"
        "C Primer Plus/Chapter9/10_4homework.c"
        Object/lcd_test/lcd_red.c
        "C Primer Plus/Chapter9/10_5homework.c"
        "C Primer Plus/Chapter9/10_6homework.c"
        "C Primer Plus/Chapter9/10_8homework.c"
        "C Primer Plus/Chapter9/10_9homework.c"
        "C Primer Plus/Chapter9/11_1homework.c"
        "C Primer Plus/Chapter9/11_2homework.c"
        "C Primer Plus/Chapter9/11_3homework.c"
        "C Primer Plus/Chapter9/11_4homework.c"
        "C Primer Plus/Chapter9/11_5homework.c"
        "C Primer Plus/Chapter9/11_6homework.c"
        "C Primer Plus/Chapter9/11_7homework.c"
        "C Primer Plus/Chapter9/11_8homework.c"
        "C Primer Plus/Chapter9/11_9homework.c"
        "C Primer Plus/Chapter9/11_10homework.c"
        "C Primer Plus/Chapter9/11_11homework.c"
        "C Primer Plus/Chapter10/1day_mon1.c"
        "C Primer Plus/Chapter10/2no_data.c"
        "C Primer Plus/Chapter10/3some_data.c"
        "C Primer Plus/Chapter10/4day_mon2.c"
        "C Primer Plus/Chapter10/5designate.c"
        "C Primer Plus/Chapter10/6bounds.c"
        "C Primer Plus/Chapter10/7rain.c"
        "C Primer Plus/Chapter10/8pnt_add.c"
        "C Primer Plus/Chapter10/9day_mon3.c"
        "C Primer Plus/Chapter10/10sum_arr1.c"
        "C Primer Plus/Chapter10/11sum_arr2.c"
        "C Primer Plus/Chapter10/12order.c"
        "C Primer Plus/Chapter10/13pte_ops.c"
        "C Primer Plus/Chapter10/14arf.c"
        "C Primer Plus/Chapter10/15zippo1.c"
        "C Primer Plus/Chapter10/16zippo2.c"
        "C Primer Plus/Chapter10/17array2d.c"
        "C Primer Plus/Chapter10/18vararr2d.c"
        ysyxDemo/area.c
        "C Primer Plus/Chapter10/19flc.c"
        "C Primer Plus/Chapter10/12_1homework.c"
        "C Primer Plus/Chapter10/12_6homework.c"
        "C Primer Plus/Chapter10/12_7homework.c"
        "C Primer Plus/Chapter10/12_8homework.c"
        "C Primer Plus/Chapter10/12_10homework.c"
        "C Primer Plus/Chapter10/12_12homework.c"
        "C Primer Plus/Chapter10/12_13homework.c"
        "C Primer Plus/Chapter10/13_1homework.c"
        "C Primer Plus/Chapter10/13_2homework.c"
        "C Primer Plus/Chapter10/13_3homework.c"
        "C Primer Plus/Chapter10/13_4homework.c"
        "C Primer Plus/Chapter10/13_5homework.c"
        "C Primer Plus/Chapter10/13_6homework.c"
        "C Primer Plus/Chapter10/13_7homework.c"
        "C Primer Plus/Chapter10/13_8homework.c"
        "C Primer Plus/Chapter10/13_9homework.c"
        "C Primer Plus/Chapter10/13_10homework.c"
        "C Primer Plus/Chapter10/13_11homework.c"
        "C Primer Plus/Chapter10/13_12homework.c"
        "C Primer Plus/Chapter10/13_13homework.c"
        "C Primer Plus/Chapter10/13_14homework.c"
        "C Primer Plus/Chapter11/1strings1.c"
        "C Primer Plus/Chapter11/2strptr.c"
        "C Primer Plus/Chapter11/3addresses.c"
        "C Primer Plus/Chapter11/4arrchar.c"
        "C Primer Plus/Chapter11/5p_and_s.c"
        "C Primer Plus/Chapter11/6getsputs.c"
        "C Primer Plus/Chapter11/7fgets1.c"
        "C Primer Plus/Chapter11/8fgets2.c"
        "C Primer Plus/Chapter11/9fgets3.c"
        "C Primer Plus/Chapter11/10s_gets.c"
        "C Primer Plus/Chapter11/11scan__str.c"
        "C Primer Plus/Chapter11/12put_out.c"
        "C Primer Plus/Chapter11/13nono.c"
        "C Primer Plus/Chapter11/14put1.c"
        "C Primer Plus/Chapter11/15put2.c"
        "C Primer Plus/Chapter11/16put_put.c"
        "C Primer Plus/Chapter11/17test_fit.c"
        "C Primer Plus/Chapter11/18str_cat.c"
        "C Primer Plus/Chapter11/19join_chk.c"
        "C Primer Plus/Chapter11/20nogo.c"
        "C Primer Plus/Chapter11/21compare.c"
        "C Primer Plus/Chapter11/22comback.c"
        "C Primer Plus/Chapter11/23quit_chk.c"
        "C Primer Plus/Chapter11/24starsrch.c"
        "C Primer Plus/Chapter11/25copy1.c"
        "C Primer Plus/Chapter11/26copy2.c"
        "C Primer Plus/Chapter11/27copy3.c"
        "C Primer Plus/Chapter11/28format.c"
        "C Primer Plus/Chapter11/29sort_str.c"
        "C Primer Plus/Chapter11/30mod_str.c"
        "C Primer Plus/Chapter11/31repeat.c"
        "C Primer Plus/Chapter11/32hello.c"
        "C Primer Plus/Chapter11/33strcnvt.c"
        "C Primer Plus/Chapter11/12_2homework.c"
        "C Primer Plus/Chapter11/12_3homework.c"
        "C Primer Plus/Chapter11/12_4homework.c"
        "C Primer Plus/Chapter11/12_5homework.c"
        "C Primer Plus/Chapter11/12_7homework.c"
        "C Primer Plus/Chapter11/12_8homework.c"
        "C Primer Plus/Chapter11/12_9homework.c"
        "C Primer Plus/Chapter11/12_10homework.c"
        "C Primer Plus/Chapter11/12_11homework.c"
        "C Primer Plus/Chapter11/12_12homework.c"
        "C Primer Plus/Chapter11/12_13homework.c"
        "C Primer Plus/Chapter11/13_1homework.c"
        "C Primer Plus/Chapter11/13_2homework.c"
        "C Primer Plus/Chapter11/13_3homework.c"
        "C Primer Plus/Chapter11/13_4homework.c"
        "C Primer Plus/Chapter11/13_5homework.c"
        "C Primer Plus/Chapter11/13_6homework.c"
        "C Primer Plus/Chapter11/13_7homework.c"
        "C Primer Plus/Chapter11/13_8homework.c"
        "C Primer Plus/Chapter11/13_9homework.c"
        "C Primer Plus/Chapter11/13_10homework.c"
        "C Primer Plus/Chapter11/13_11homework.c"
        "C Primer Plus/Chapter11/13_12homework.c"
        "C Primer Plus/Chapter11/13_13homework.c"
        "C Primer Plus/Chapter11/13_14homework.c"
        "C Primer Plus/Chapter11/13_15homework.c"
        "C Primer Plus/Chapter11/13_16homework.c"
        Chapter12/1hiding.c
        Chapter12/2forc99.c
        Chapter12/3loc_stat.c
        Chapter12/4global.c
        Chapter12/5parta.c
        Chapter12/6partb.c
        Chapter12/7rand0.c
        Chapter12/8r_drive0.c
        Chapter12/9s_and_r.c
        Chapter12/10r_drive1.c
        Chapter12/11dicerol1.c
        Chapter12/12diceroll.h
        Chapter12/13manydice.c
        Chapter12/14dyn_arr.c
        Chapter12/15where.c
        Chapter12/12_8homework.c
        Chapter12/13_1homework.c
        "Chapter12/ 13_2homework.c"
        Chapter12/13_2pe12-2a.h
        Chapter12/13_3homework.c
        Chapter12/13_3pe12-2a.h
        Chapter12/13_4homework.c
        Chapter12/13_5homework.c
        Chapter12/13_6homework.c
        Chapter12/13_7homework.c
        Chapter12/13_8homework.c
        Chapter12/13_9homework.c
        "C Primer Plus/Chapter13/1count.c"
        "C Primer Plus/Chapter13/2reducto.c"
        "C Primer Plus/Chapter13/3addaword.c"
        "C Primer Plus/Chapter13/4reverse.c"
        "C Primer Plus/Chapter13/5append.c"
        "C Primer Plus/Chapter13/6randbin.c"
        "C Primer Plus/Chapter13/10_3homework.c"
        "C Primer Plus/Chapter13/10_4homework.c"
        "C Primer Plus/Chapter13/10_5homework.c"
        Leetcode/BasicLevel/1numIdenticalPairs.c
        Leetcode/BasicLevel/2countGoodTriplets.c
        Leetcode/BasicLevel/3toLowerCase.c
        "C Primer Plus/Chapter14/1book.c"
        "C Primer Plus/Chapter14/2manybook.c"
        "C Primer Plus/Chapter14/3friend.c"
        "C Primer Plus/Chapter14/4friends.c"
        "C Primer Plus/Chapter14/5funds1.c"
        "C Primer Plus/Chapter14/6funds2.c"
        "C Primer Plus/Chapter14/7funds3.c"
        "C Primer Plus/Chapter14/8names1.c"
        "C Primer Plus/Chapter14/9names2.c"
        "C Primer Plus/Chapter14/10name3.c"
        "C Primer Plus/Chapter14/11complit.c"
        "C Primer Plus/Chapter14/7flexmemb.c"
        "C Primer Plus/Chapter14/13funds4.c"
        "C Primer Plus/Chapter14/14booksave.c"
        "C Primer Plus/Chapter14/15enum.c"
        "C Primer Plus/Chapter14/16func_ptr.c"
        "C Primer Plus/Chapter14/17homework02.c"
        "C Primer Plus/Chapter14/17homework03.c"
        "C Primer Plus/Chapter15/1binbit.c"
        "C Primer Plus/Chapter15/2invert4.c"
        "C Primer Plus/Chapter15/3fields.c"
        "C Primer Plus/Chapter15/4dualview.c"
        "C Primer Plus/Chapter15/5align.c"
        "C Primer Plus/Chapter16/1preproc.c"
        "C Primer Plus/Chapter16/2mac_arg.c"
        "C Primer Plus/Chapter16/3subset.c"
        "C Primer Plus/Chapter16/4glue.c"
        "C Primer Plus/Chapter16/5variadic.c"
        "C Primer Plus/Chapter16/7names_st.c"
        "C Primer Plus/Chapter16/6names_st.h"
        "C Primer Plus/Chapter16/8useheader.c"
        "C Primer Plus/Chapter16/9ifdef.c"
        "C Primer Plus/Chapter16/10names.h"
        "C Primer Plus/Chapter16/11doubincl.c"
        "C Primer Plus/Chapter16/12predef.c"
        "C Primer Plus/Chapter16/13mytype.c"
        "C Primer Plus/Chapter16/14rect_pol.c"
        "C Primer Plus/Chapter16/15generic.c"
        "C Primer Plus/Chapter16/16byebye.c"
        "C Primer Plus/Chapter16/17qsorter.c"
        "C Primer Plus/Chapter16/18assert.c"
        "C Primer Plus/Chapter16/19statasrt.c"
        "C Primer Plus/Chapter16/20mems.c"
        "C Primer Plus/Chapter16/21varargs.c"
        "C Primer Plus/Chapter17/1films1.c"
        "C Primer Plus/Chapter17/2film2.c"
        "C Primer Plus/Chapter17/3list.h"
        "C Primer Plus/Chapter17/4film3.c"
        "C Primer Plus/Chapter17/5list.c"
        "C Primer Plus/Chapter17/6queue.h"
        "C Primer Plus/Chapter17/7queue.c"
        "C Primer Plus/Chapter17/8use_q.c"
        "C Primer Plus/Chapter17/9queue.h"
        "C Primer Plus/Chapter17/9mall.c"
        "C Primer Plus/Chapter17/10tree.h"
        "C Primer Plus/Chapter17/11tree.c"
        "C Primer Plus/Chapter17/12petclub.c"
        "C++ Primer Plus/Chapter1/1helloworld.cpp"
)
