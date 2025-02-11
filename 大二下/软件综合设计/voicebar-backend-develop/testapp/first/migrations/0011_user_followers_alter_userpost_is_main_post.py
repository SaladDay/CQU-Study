# Generated by Django 4.1 on 2022-08-12 20:33

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('first', '0010_userpost_is_main_post_userpost_reply_to'),
    ]

    operations = [
        migrations.AddField(
            model_name='user',
            name='followers',
            field=models.ManyToManyField(to='first.user'),
        ),
        migrations.AlterField(
            model_name='userpost',
            name='is_main_post',
            field=models.BooleanField(default=True),
        ),
    ]
