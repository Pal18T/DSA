# Write your MySQL query statement below

select s.student_id, s.student_name, su.subject_name , count(ex.student_id) as attended_exams from Students s
cross join Subjects su 
left join Examinations ex
on s.student_id=ex.student_id and su.subject_name = ex.subject_name
Group by s.student_id,s.student_name, su.subject_name
Order by s.student_id,s.student_name, su.subject_name;
