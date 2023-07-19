CREATE TABLE parents AS
  SELECT "abraham" AS parent, "barack" AS child UNION
  SELECT "abraham"          , "clinton"         UNION
  SELECT "delano"           , "herbert"         UNION
  SELECT "fillmore"         , "abraham"         UNION
  SELECT "fillmore"         , "delano"          UNION
  SELECT "fillmore"         , "grover"          UNION
  SELECT "eisenhower"       , "fillmore";

CREATE TABLE dogs AS
  SELECT "abraham" AS name, "long" AS fur, 26 AS height UNION
  SELECT "barack"         , "short"      , 52           UNION
  SELECT "clinton"        , "long"       , 47           UNION
  SELECT "delano"         , "long"       , 46           UNION
  SELECT "eisenhower"     , "short"      , 35           UNION
  SELECT "fillmore"       , "curly"      , 32           UNION
  SELECT "grover"         , "short"      , 28           UNION
  SELECT "herbert"        , "curly"      , 31;

CREATE TABLE sizes AS
  SELECT "toy" AS size, 24 AS min, 28 AS max UNION
  SELECT "mini"       , 28       , 35        UNION
  SELECT "medium"     , 35       , 45        UNION
  SELECT "standard"   , 45       , 60;


-- All dogs with parents ordered by decreasing height of their parent
CREATE TABLE by_parent_height AS
  -- SELECT "REPLACE THIS LINE WITH YOUR SOLUTION";
  -- chatgpt提供语法，我修改逻辑
  SELECT p.child
  FROM dogs d
  LEFT JOIN parents p ON d.name = p.child
  ORDER BY (SELECT height FROM dogs WHERE name = p.parent)
           DESC;


-- The size of each dog
CREATE TABLE size_of_dogs AS
  -- SELECT "REPLACE THIS LINE WITH YOUR SOLUTION";
  SELECT d.name, s.size
  FROM dogs d
  JOIN sizes s ON d.height > s.min AND d.height <= s.max; -- 还是第一次知道能这么写，一直以为只能是 ON 然后 =


-- -- Filling out this helper table is optional
-- CREATE TABLE siblings AS
--   SELECT "REPLACE THIS LINE WITH YOUR SOLUTION";

-- -- Sentences about siblings that are the same size
-- CREATE TABLE sentences AS
--   SELECT "REPLACE THIS LINE WITH YOUR SOLUTION";

-- Creating the siblings table
-- 按照chatgpt的做法，是用JOIN，我跟着这么想不知道怎么做到dogs JOIN dogs，只好上网找答案，没想到压根就不用 JOIN 。。
-- 还有，英文不好，不知道居然还是要同个父母 a.parent = b.parent
-- 另外，我本来还在想着怎么比较相同大小，忘了已经有 size_of_dogs 这张表了
CREATE TABLE siblings AS
  SELECT a.child AS aname, b.child AS bname, sa.size AS asize, sb.size AS bsize 
        FROM parents AS a, parents AS b, size_of_dogs AS sa, size_of_dogs AS sb 
        WHERE a.parent = b.parent AND aname < bname AND sa.name = aname AND sb.name = bname;

-- Creating the sentences table
CREATE TABLE sentences AS
  SELECT "The two siblings, " || aname || " plus " || bname
        || " have the same size: "|| asize
        FROM siblings WHERE asize = bsize;