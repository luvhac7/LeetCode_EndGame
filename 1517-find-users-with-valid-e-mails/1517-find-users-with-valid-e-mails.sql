SELECT *
FROM Users u
WHERE REGEXP_LIKE(
        u.mail,
        '^[A-Za-z][A-Za-z0-9._-]*@leetcode\\.com$',
        'c'
      );